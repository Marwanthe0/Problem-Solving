# Competitive Programming and DSA Archive

Personal archive of Data Structures, Algorithms, and Competitive Programming solutions developed during university studies. The repository tracks problem-solving progress across major online judges, contest platforms, national programming camps, and structured training sheets.

The collection contains over 2,200 solutions, primarily implemented in C++ (C++17 / C++20 standard).

---

## Directory Overview

| Directory | Description | Scope / Organization |
| :--- | :--- | :--- |
| `CP-31 Sheet` | Solutions from the CP-31 practice sheet | Organized by Codeforces rating tiers (1000 to 1700) |
| `CSES` | CSES Problem Set solutions | Categorized by topic (DP, Graphs, Trees, Math, Sorting) |
| `XPSC_Phitron` | Intensive competitive programming track | 19 weeks of daily problem sets (Week 1 to Week 19) |
| `CodeForces Contests` | Live and practice Codeforces contest rounds | Div 1+2, Div 2, Div 3, Div 4, and Educational rounds |
| `AtCoder Contest` | AtCoder contests and curated problem sets | ABC, ARC rounds, and the full Educational DP Contest |
| `CodeChef Contest` | CodeChef contest submissions | Starters, Cook-Off, and rated challenge rounds |
| `Practice` | IUPC replays and inter-university contests | CUET, DUET, SUST, IUT, MU, MBSTU, and Intra-LU contests |
| `SUST CP Camp 2026` | Training camp problem sets | Geometry, Number Theory, Combinatorics, and Graph Theory |
| `Virtual Contest` | Virtual contest simulations | Codeforces rounds, IUT Eid Salami, NDUB IUPC, Toph NHSPC |
| `2025 Monthly` | Continuous practice logs throughout 2025 | Grouped by month (March through December) |
| `2024 Random` | Early practice archives and standalone problems | General algorithmic problems and initial implementations |
| `Dynamic Programming` | Focused DP practice | Bitmask DP and Codeforces DP problem sets |
| `Graph Problems` | Graph-specific practice | Shortest paths, traversal, and connectivity |
| `Codeforces Greedy` | Greedy algorithm practice | Codeforces constructive and greedy problems |
| `LightOj` | LightOJ problem solutions | Classic dynamic programming and math problems |
| `Unacademy` | Curated course problem sets | Number theory and combinatorics problems |
| `UPSOLVE` | Post-contest problem resolutions | Upsolved contest problems requiring in-depth analysis |
| `LeetCode Contest` | LeetCode contest rounds | Weekly and biweekly contest problems |
| `SeriousOJ Contest` | SeriousOJ rounds | Educational and rated contest rounds |
| `More ja Problem Solve kor` | Additional daily problem solving | Targeted Codeforces practice problems |
| `Resources` | Reference material and configuration | Team notebooks, KACTL, CP handbooks, and VS Code snippets |

---

## Platforms and Problem Sets

### CP-31 Sheet
Targeted problem sets for Codeforces rating progression:
- 1000 Rating
- 1100 Rating
- 1200 Rating
- 1300 Rating
- 1400 Rating
- 1500 Rating
- 1600 Rating
- 1700 Rating

### CSES Problem Set
Implementation of foundational algorithms and data structures:
- Introductory Problems
- Searching and Sorting
- Dynamic Programming
- Graph Algorithms
- Tree Algorithms
- Mathematics and Number Theory

### XPSC Curriculum
Structured 19-week curriculum covering competitive programming techniques:
- Weekly breakdown from `Week_1` to `Week_19`
- Day-wise problem distributions (`Day_1` through `Day_7`)
- Techniques covered: Sliding window, two pointers, bit manipulation, prefix sums, binary search, graph traversal, and dynamic programming

### Collegiate Contests and IUPC Replays
Archived submissions from national programming contests and university contest replays:
- Intra Leading University (LU) Contests
- CUET IUPC
- DUET IUPC
- SUST IUPC
- IUT IUPC / IUT Eid Salami
- MBSTU Eid Salami
- MU IUPC
- National Girls Programming Contest (NGPC)
- Toph NHSPC

---

## Core Topics Covered

- Dynamic Programming: 1D/2D DP, Bitmask DP, Knapsack variants, Longest Common Subsequence, Grid DP, Digit DP, Tree DP
- Graph Theory: BFS, DFS, Dijkstra, Bellman-Ford, Floyd-Warshall, Topological Sort, Disjoint Set Union (DSU), Minimum Spanning Tree
- Number Theory and Math: Sieve of Eratosthenes, Prime Factorization, Modular Arithmetic, Modular Inverse, GCD/LCM, Combinatorics
- Searching and Sorting: Binary Search, Binary Search on Answer, Ternary Search, Two Pointers, Coordinate Compression
- Data Structures: Segment Trees, Fenwick Trees (Binary Indexed Trees), Stacks, Queues, Priority Queues, Policy-Based Data Structures (PBDS)
- Greedy and Constructive: Interval scheduling, prefix sum optimizations, exchange arguments, invariant analysis

---

## Development Environment and Toolchain

- Language: C++ (primarily compiled with C++17 or C++20)
- Secondary Languages: C, Java, Python (used for specific tasks, big integer handling, or scripts)
- Compiler: GCC / MinGW (`g++`)
- Editor: Visual Studio Code
- Testing Tools: Competitive Companion, Competitive Programming Helper (`cph`)

### Compilation

Standard compilation with optimization and warning flags:

```bash
g++ -O3 -std=c++17 -Wall solution.cpp -o solution
./solution
```

For debugging with address sanitizer and strict checks:

```bash
g++ -std=c++17 -Wall -Wextra -Wshadow -fsanitize=address,undefined -g solution.cpp -o debug
./debug
```

---

## Author

- GitHub: [Marwanthe0](https://github.com/Marwanthe0)
