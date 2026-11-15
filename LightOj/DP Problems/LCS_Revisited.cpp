#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000007
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
string a, b;
int n, m;
vector<vector<int>> dp, dp2;
int f(int i, int j) {
    if (i == n || j == m)
        return dp[i][j] = 0;
    int &ans = dp[i][j];
    if (ans != -1)
        return ans;
    if (a[i] == b[j])
        return dp[i][j] = 1 + f(i + 1, j + 1);
    return dp[i][j] = max({f(i + 1, j), f(i, j + 1)});
}

int f2(int i, int j) {
    if (i == n || j == m) {
        return 1;
    }
    // if (dp[i][j] == 0)
    //     return 1;
    if (dp2[i][j] != -1)
        return dp2[i][j];

    int ans = 0;
    if (a[i] != b[j]) {
        if (f(i, j) == f(i + 1, j))
            ans = (ans + f2(i + 1, j)) % M;
        if (f(i, j) == f(i, j + 1))
            ans = (ans + f2(i, j + 1)) % M;
        if (f(i, j) == f(i + 1, j + 1))
            ans = ((ans % M) - (f2(i + 1, j + 1) % M) + M) % M;
    } else
        ans = (ans + f2(i + 1, j + 1)) % M;

    return dp2[i][j] = ans;
}
void marwan(int cs) {
    cin >> a >> b;
    n = a.size(), m = b.size();
    dp.assign(n + 1, vector<int>(m + 1, -1));
    dp2.assign(n + 1, vector<int>(m + 1, -1));
    int lcs = f(0, 0);
    if (!lcs) {
        cout << 1 << endl;
        return;
    }
    int ans = f2(0, 0);
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