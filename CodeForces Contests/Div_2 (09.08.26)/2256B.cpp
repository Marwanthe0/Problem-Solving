#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
string s;
vector<vector<vector<int>>> dp;
int f(int i, int last, int slast) {
    if (i == n)
        return 1ll;
    if (dp[i][last][slast] != -1)
        return dp[i][last][slast];
    if (i == 0) {
        if (s[i] == '?') {
            return dp[i][last][slast] = (f(i + 1, 0, slast) % M + f(i + 1, 1, slast) % M) % M;
        } else
            return dp[i][last][slast] = (f(i + 1, s[i] - '0', slast)) % M;
    } else if (i == 1) {
        if (s[i] == '?')
            return dp[i][last][slast] = (f(i + 1, 0, last) % M + f(i + 1, 1, last) % M) % M;
        else
            return dp[i][last][slast] = (f(i + 1, s[i] - '0', last)) % M;
    }
    if (s[i] == '?')
        return dp[i][last][slast] = (f(i + 1, !slast, last)) % M;
    else if (s[i] - '0' != (1 - slast))
        return dp[i][last][slast] = (0) % M;
    else
        return dp[i][last][slast] = (f(i + 1, 1 - slast, last)) % M;
}
void marwan() {
    cin >> n;
    cin >> s;
    dp.assign(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));
    int ans = f(0, 0, 0);
    cout << ans % M << endl;
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