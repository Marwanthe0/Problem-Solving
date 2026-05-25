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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp[i][j] = longest common subs in a[0...i] with b[0...j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) { // ith value in a == jth value in b
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // maximum of answer in i - 1th and in j - 1th
        }
    }
    cout << dp[n][m] << endl;
    vector<int> ans;
    int i = n, j = m;
    while (i && j) {
        if (a[i - 1] == b[j - 1])
            ans.push_back(a[i - 1]), i--, j--;
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(all(ans));
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}