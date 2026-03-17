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
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    int sum = 0, flag = 0;
    for (auto &vl : v) {
        cin >> vl;
        if (vl == 0)
            flag = 1;
        sum += vl;
        if ((sum % m) == 0) {
            yes;
            return;
        }
    }
    if (n > m || flag) {
        yes;
        return;
    }
    for (auto &vl : v) {
        vl %= m;
    }
    vector<int> dp(m + 1, 0), ndp(m + 1, 0);
    for (int i = 0; i < n; i++) {
        ndp = dp;
        ndp[v[i]] = 1;
        for (int j = 0; j <= m; j++) {
            if (dp[j])
                ndp[(j + v[i]) % m] = 1;
        }
        dp = ndp;
        if (ndp[0]) {
            yes;
            return;
        }
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}