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
int base, k;
string s;
int dp[1 << 13][20];
int conv(char c) {
    int d = 0;
    if (c >= '0' and c <= '9')
        d = c - '0';
    else {
        d = 10 + (c - 'A');
    }
    return d;
}
int f(int mask, int sum) {
    int i = __builtin_popcount(mask);
    if (i == s.size()) {
        return sum % k == 0;
    }
    if (~dp[mask][sum])
        return dp[mask][sum];
    int ans = 0;
    for (int j = 0; j < s.size(); j++) {
        if (((mask) & (1 << j)) == 0) {
            ans += f(mask | (1 << j), (sum * base + conv(s[j])) % k);
        }
    }
    return dp[mask][sum] = ans;
}
void marwan(int cs) {
    cin >> base >> k;
    cin >> s;
    memset(dp, -1, sizeof dp);
    int ans = f(0, 0);
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