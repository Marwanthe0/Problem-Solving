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
int n;
vector<int> v;
vector<vector<vector<int>>> dp;
int f(int i, int l, int r) {
    if (i == n)
        return 0;
    if (dp[i][l][r] != -1)
        return dp[i][l][r];
    int nimuna = f(i + 1, l, r);
    int left = 0, right = 0;
    // left e nimu
    if (l == n || v[i] >= v[l]) {
        if (r == n || v[i] <= v[r])
            left = 1 + f(i + 1, i, r);
    }
    // right e nimu
    if (r == n || v[i] <= v[r]) {
        if (l == n || v[i] >= v[l])
            right = 1 + f(i + 1, l, i);
    }
    return dp[i][l][r] = max({nimuna, left, right});
}
void marwan(int cs) {
    cin >> n;
    v.assign(n, 0);
    for (auto &vl : v)
        cin >> vl;
    dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
    int ans = f(0, n, n);
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