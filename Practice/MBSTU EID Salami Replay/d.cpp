#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
string name = "ARIFIN";
string cur;
unordered_set<char> st = {'A', 'R', 'I', 'F', 'N'};
map<int, string> a = {{1, "7A"}, {2, "7B"}, {3, "7R"}, {4, "7S"}, {5, "7I"}, {6, "7F"}, {7, "7N"}};
// int32_t dp[50][10][10005];
// int32_t vis[50][10][10005];
// int32_t tc_id = 0;

// int f(int i, int j, int tn) {
//     if (i < 0) {
//         if (tn <= 0)
//             return 0;
//         else
//             return f((int)cur.size() - 1, j, tn - 1);
//     }
//     if (j < 0)
//         return 1;
//     if (vis[i][j][tn] == tc_id)
//         return dp[i][j][tn];
//     int nimuna = f(i - 1, j, tn);
//     int nimu = 0;
//     if (cur[i] == name[j]) {
//         nimu = f(i - 1, j - 1, tn);
//     }
//     nimuna %= M;
//     nimu %= M;
//     vis[i][j][tn] = tc_id;
//     return dp[i][j][tn] = (nimu + nimuna) % M;
// }

void marwan() {
    // tc_id++;
    int n, k;
    cin >> k >> n;
    vector<string> ans;
    while (k) {
        if (a.count(k) && k <= 7) {
            ans.push_back(a[k]);
            break;
        }
        int x = k % 7;
        if (x == 0)
            x = 7;
        ans.push_back(a[x]);
        k = (k / 7) + (k % 7 != 0);
    }
    reverse(ans.begin(), ans.end());
    string tt;
    for (auto s : ans) {
        if (st.count(s[1]))
            tt.push_back(s[1]);
    }
    cur = tt;
    if (cur.empty()) {
        cout << "NO\n";
        return;
    }
    int ways[7] = {0};
    ways[0] = 1;
    for (int rep = 0; rep < n; rep++) {
        for (char c : cur) {
            for (int k = 6; k >= 1; k--) {
                if (c == name[k - 1]) {
                    ways[k] = (ways[k] + ways[k - 1]) % M;
                }
            }
        }
    }
    int uttor = ways[6];
    if (uttor) {
        cout << "YES\n";
        cout << uttor << "\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    if (cin >> t) {
        while (t--) {
            marwan();
        }
    }
    return 0;
}