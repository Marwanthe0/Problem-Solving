#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, l, k;
vector<int> a, b;
// vector<vector<vector<int>>> dp;
// int f(int i, int last_time, int op) {
//     if (i == n) {
//         return (l - a[last_time]) * (b[last_time]);
//     }
//     if (dp[i][last_time][op] != -1)
//         return dp[i][last_time][op];
//     int nibo = f(i + 1, i, op) + (a[i] - a[last_time]) * (b[last_time]), nibona = INT_MAX;
//     if (op) {
//         nibona = f(i + 1, last_time, op - 1);
//     }
//     return dp[i][last_time][op] = min(nibo, nibona);
// }
void marwan() {
    cin >> n >> l >> k;
    a.assign(n, 0);
    b.assign(n, 0);
    // dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    vector<vector<int>> next(n + 1, vector<int>(k + 1, 0)), prev(n + 1, vector<int>(k + 1, 0));
    for (int i = n; i >= 1; i--) {
        for (int last_time = n - 1; last_time >= 0; last_time--) {
            for (int op = 0; op <= k; op++) {
                if (i == n)
                    next[last_time][op] = ((l - a[last_time]) * (b[last_time]));
                else {
                    int nibo = prev[i][op] + (a[i] - a[last_time]) * (b[last_time]), nibona = INT_MAX;
                    if (op) {
                        nibona = prev[last_time][op - 1];
                    }
                    next[last_time][op] = min(nibo, nibona);
                }
            }
        }
        prev = next;
    }
    int ans = next[0][k];
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}