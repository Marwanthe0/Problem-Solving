#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
string s;
int n;
void marwan() {
    cin >> s;
    n = s.size();
    vector<int> dp(n + 1, 0);
    for (auto c : s)
        if (c == 'm' or c == 'w') {
            zero;
            return;
        }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (i > 1 && s[i - 1] == s[i - 2] && (s[i - 1] == 'n' || s[i - 1] == 'u'))
            dp[i] = (dp[i] + dp[i - 2] % M) % M;
    }
    cout << dp[n] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}