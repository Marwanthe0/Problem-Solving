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
vector<vector<int>> v;
vector<int> dp;

int f(int i, int mask) {
    int sum = v[i][i];
    for (int j = 0; j < n; j++) {
        if (i != j && (mask & (1ll << j))) {
            sum += v[i][j];
        }
    }
    if (mask == (1ll << n) - 1) {
        return sum;
    }
    if (dp[mask] != -1)
        return sum + dp[mask];

    int ans = 1e9;
    for (int j = 0; j < n; j++) {
        if ((mask & (1ll << j)) == 0) {
            ans = min(ans, f(j, mask | (1ll << j)));
        }
    }
    dp[mask] = ans;
    return sum + ans;
}

void marwan(int cs) {
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> v[i][j];
    }
    // done
    int msk = (1ll << n);
    dp.assign(msk, -1);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, f(i, (1ll << i)));
    }
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