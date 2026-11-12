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
int dp[33][2][2][33][2];
int f(int i, bool tight, bool lz, int cnt, bool prev, string &s) {
    if (i == s.size()) {
        return dp[i][tight][lz][cnt][prev] = cnt;
    }
    if (dp[i][tight][lz][cnt][prev] != -1)
        return dp[i][tight][lz][cnt][prev];
    int high = tight ? s[i] - '0' : 1;
    int ans = 0;
    for (int d = 0; d <= high; d++) {
        bool nlz = (lz && d == 0);
        int ncnt = cnt + (d && prev);
        ans += f(i + 1, tight && d == high, nlz, ncnt, d, s);
    }
    return dp[i][tight][lz][cnt][prev] = ans;
}
void marwan(int cs) {
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    string s;
    for (int i = __lg(n); i >= 0; i--)
        s.push_back((1 & (n >> i)) + '0');
    n = s.size();
    
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 1, 0, 0, 0, s);
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