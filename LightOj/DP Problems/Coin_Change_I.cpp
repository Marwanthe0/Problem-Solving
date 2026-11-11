#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 100000007
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
int n, k;
vector<int> a, b;
vector<vector<int>> dp;
int f(int i, int sum) {
    if (sum <= 0)
        return sum == 0;
    if (i == n)
        return 0;
    if (dp[i][sum] != -1)
        return dp[i][sum];

    int ans = f(i + 1, sum);
    for (int j = 1; j <= b[i]; j++) {
        if (sum >= j * a[i])
            ans = (ans + f(i + 1, sum - (j * a[i]))) % M;
        else
            break;
    }
    return dp[i][sum] = ans;
}
void marwan(int cs) {
    cin >> n >> k;
    a.assign(n, 0);
    b.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    dp.assign(n + 1, vector<int>(k + 1, -1));
    int ans = f(0, k);
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