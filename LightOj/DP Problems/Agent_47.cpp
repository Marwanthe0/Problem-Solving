#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> v;
vector<int> health;
int dp[1 << 16];
int f(int mask) {
    if (__builtin_popcount(mask) == n)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];
    vector<int> mxs(n, 0);

    for (int i = 0; i < n; i++) {
        if ((1 & (mask >> i)) == 1) {
            
            for (int j = 0; j < n; j++) {
                mxs[j] = max(mxs[j], v[i][j]);
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if ((mask & (1ll << i)) == 0) {
            ans = min(ans, health[i] + f(mask | (1ll << i)));

            if (mxs[i])
                ans = min(ans, f(mask | (1ll << i)) + (health[i] / mxs[i]) + (health[i] % mxs[i] != 0));
        }
    }
    return dp[mask] = ans;
}
void marwan(int cs) {
    cin >> n;
    health.assign(n, 0);
    v.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            v[i][j] = s[j] - '0';
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = f(0);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}