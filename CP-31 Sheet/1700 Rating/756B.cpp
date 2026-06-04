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
    int n;
    cin >> n;
    vector<int> dp(n, INT_MAX);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
        int nobboi = upper_bound(v.begin(), v.begin() + i, x - 90) - v.begin(), ekdin = upper_bound(v.begin(), v.begin() + i, x - 1440) - v.begin();
        dp[i] = (i ? dp[i - 1] : 0)+20;
        dp[i] = min(dp[i], (nobboi ? dp[nobboi - 1] : 0) + 50);
        dp[i] = min(dp[i], (ekdin ? dp[ekdin - 1] : 0) + 120);
        cout << dp[i] - (i ? dp[i - 1] : 0) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}