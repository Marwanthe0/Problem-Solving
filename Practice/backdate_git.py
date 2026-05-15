import os
import subprocess
from datetime import datetime

# 1. SET YOUR PROJECT PATH HERE (Use 'r' before the string for Windows paths)
TARGET_DIR = r"C:\CSE"


def build_backdated_repo():
    os.chdir(TARGET_DIR)

    # Initialize a fresh git repository
    if not os.path.exists(".git"):
        print("Initializing new Git repository...")
        subprocess.run(["git", "init"], check=True)
        subprocess.run(["git", "branch", "-M", "main"], check=True)

    files_to_commit = []

    # Gather all files
    for root, dirs, files in os.walk("."):
        if ".git" in root.split(os.sep):
            continue

        for file in files:
            filepath = os.path.join(root, file)
            timestamp = os.path.getmtime(filepath)
            files_to_commit.append((filepath, timestamp))

    # Sort files from oldest to newest
    files_to_commit.sort(key=lambda x: x[1])

    print(f"Found {len(files_to_commit)} files. Starting historical commits...\n")

    for filepath, timestamp in files_to_commit:
        git_filepath = filepath.replace(os.sep, "/")

        # 1. Try to add the file
        try:
            subprocess.run(
                ["git", "add", git_filepath], check=True, stderr=subprocess.PIPE
            )
        except subprocess.CalledProcessError:
            print(f"⏩ Skipping ignored file: {git_filepath}")
            continue

        dt = datetime.fromtimestamp(timestamp)
        date_str = dt.strftime("%Y-%m-%d %H:%M:%S")

        custom_env = os.environ.copy()
        custom_env["GIT_AUTHOR_DATE"] = date_str
        custom_env["GIT_COMMITTER_DATE"] = date_str

        commit_msg = f"Add {os.path.basename(git_filepath)}"

        # 2. THE FIX: Try to commit, skip if Git says there is nothing to commit
        try:
            subprocess.run(
                ["git", "commit", "-m", commit_msg],
                env=custom_env,
                check=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            print(f"Committing: {git_filepath} | Date: {date_str}")
        except subprocess.CalledProcessError:
            print(f"⏩ Skipping commit: {git_filepath} (Nothing changed or empty file)")

    print("\n✅ All files processed successfully!")


if __name__ == "__main__":
    build_backdated_repo()
