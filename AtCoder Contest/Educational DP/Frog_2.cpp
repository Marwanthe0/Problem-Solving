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
int f(int i, vector<int> &v, vector<int> &dp, int k) {
    if (i + 1 >= v.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    for (int tk = 1; tk <= k; tk++) {
        if (i + tk < v.size()) {
            ans = min(ans, f(i + tk, v, dp, k) + abs(v[i] - v[i + tk]));
        }
    }
    return dp[i] = ans;
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> dp(n + 1, -1);
    int ans = f(0, v, dp, k);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}