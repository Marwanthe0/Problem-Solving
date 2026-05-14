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
int d, n;
string s;
int32_t dp[100000][2][2][100];
int f(int i, bool tight, bool lz, int val) {
    if (i == n) {
        return (!lz) && (val == 0);
    }
    if (dp[i][tight][lz][val] != -1)
        return dp[i][tight][lz][val];
    int lim = tight ? s[i] - '0' : 9;
    int ans = 0ll;
    for (int j = 0; j <= lim; j++) {
        bool nlz = lz && (j == 0);
        ans = (ans + f(i + 1, tight && (j == lim), nlz, (val + j) % d)) % M;
    }
    return dp[i][tight][lz][val] = ans;
}
void marwan() {
    cin >> s;
    cin >> d;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 1, 1, 0);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}