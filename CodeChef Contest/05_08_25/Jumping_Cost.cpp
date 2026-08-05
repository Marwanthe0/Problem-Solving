#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
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
vector<int> v;
vector<vector<int>> dp;
int f(int i, int last) {
    if (i > n) {
        return 0;
    }
    if (dp[i][last] != -1)
        return dp[i][last];
    int nibo = f(i + 1, i) + v[i] - i + last, nibona = f(i + 1, last);
    return dp[i][last] = max(nibo, nibona);
}
void marwan() {
    cin >> n;
    v.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int ans = f(2, 1);
    cout << ans << endl;
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