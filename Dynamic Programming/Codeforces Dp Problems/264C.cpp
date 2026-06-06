#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define INF 1e15
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int n, q;
vector<int> v, c;
int a, b;
vector<int> dp;
void marwan() {
    cin >> n >> q;
    v.resize(n, 0);
    c.resize(n, 0);
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : c) {
        cin >> vl;
        vl--;
    }
    while (q--) {
        cin >> a >> b;
        dp.assign(n + 1, -INF);
        int mx1 = 0, mx2 = 0;
        for (int i = 0; i < n; i++) {
            if (mx1 == dp[c[i]]) {
                dp[c[i]] = max(dp[c[i]], dp[c[i]] + a * v[i]);
                dp[c[i]] = max(dp[c[i]], mx2 + b * v[i]);
                mx1 = max(mx1, dp[c[i]]);
            } else {
                dp[c[i]] = max(dp[c[i]], dp[c[i]] + a * v[i]);
                dp[c[i]] = max(dp[c[i]], mx1 + b * v[i]);
                mx2 = max(mx2, dp[c[i]]);
                if (mx2 > mx1)
                    swap(mx2, mx1);
            }
        }
        cout << mx1 << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}