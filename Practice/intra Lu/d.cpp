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
int f(int i, vector<int> &v, int k, vector<int> &dp) {
    if (i >= v.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int nimuna = f(i + 1, v, k, dp), nimu = f(i + k, v, k, dp) + v[i];
    return dp[i] = max(nimuna, nimu);
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> dp(n + 1, -1);
    int ans = f(k - 1, v, k, dp);
    cout << ans << endl;
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