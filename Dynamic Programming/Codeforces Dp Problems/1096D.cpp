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
set<char> check = {'h', 'a', 'r', 'd'};
map<char, int> mp;
void marwan() {
    mp['h'] = 0, mp['a'] = 1, mp['r'] = 2, mp['d'] = 3;
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> dp(n + 1, vector<int>(4, 1e17));
    dp[0][0] = 0ll;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            if (!check.count(s[i - 1])) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            if (mp[s[i - 1]] == j)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + v[i - 1]);
            else if (mp[s[i - 1]] == j - 1)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << *min_element(all(dp[n])) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}