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
string s;
int n;
int dp[61][61][2];
int f(int i, int j, bool found) {
    if (i > j)
        return found;

    if (dp[i][j][found] != -1)
        return dp[i][j][found];
    int ans = f(i + 1, j, found) + f(i, j - 1, found) - f(i + 1, j - 1, found);

    if (s[i] == s[j])
        ans = (ans + f(i + 1, j - 1, 1));
    // return ans;
    return dp[i][j][found] = ans;
}
void marwan(int cs) {
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1, 0) << endl;
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