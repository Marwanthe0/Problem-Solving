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
int f(int i, int j, string &s, string &t) {
    if (i < 0 || j < 0)
        return 0;
    if (s[i] == t[j])
        return f(i - 1, j - 1, s, t) + 1;
    else
        return max(f(i - 1, j, s, t), f(i, j - 1, s, t));
}
void marwan() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    // int ans = f(n - 1, m - 1, s, t);
    // cout << ans << endl;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int i = n, j = m;
    string lcs;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1])
            lcs.push_back(s[i - 1]), i--, j--;
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(all(lcs));
    cout << lcs << endl;
    // cout << dp[n][m] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}