#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 2e5
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, k;
vector<int> v;
int dp[(int32_t)N + 1][64][2];
int f(int i, int op, bool taken) {
    if (i < 0) {
        return taken && __builtin_popcountll(op) == k;
    }
    if (__builtin_popcountll(op) < k) {
        return 0ll;
    }
    if (dp[i][op][taken] != -1)
        return dp[i][op][taken];
    int nimu = 0ll;
    int nimuna = f(i - 1, op, taken);
    if (__builtin_popcountll(op & v[i]) >= k)
        nimu += f(i - 1, op & v[i], true);
    return dp[i][op][taken] = (nimu + nimuna) % M;
}
void marwan() {
    cin >> n >> k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 64; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    for (auto &vl : v)
        cin >> vl;
    int ans = f(n - 1, 63, false);
    cout << ans << endl;
    // yes;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}