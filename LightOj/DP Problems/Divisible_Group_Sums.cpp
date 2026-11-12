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
int n, q, m, d;
vector<int> v;
vector<vector<vector<int>>> dp;
int f(int i, int cnt, int sum) {
    if (cnt == m)
        return ((sum % d) == 0);
    if (i == n)
        return 0;
    if (dp[i][cnt][sum] != -1)
        return dp[i][cnt][sum];
    int ans = f(i + 1, cnt, sum);
    if (cnt < m)
        ans += f(i + 1, cnt + 1, ((sum + v[i]) % d + d) % d);
    return dp[i][cnt][sum] = ans;
}
void marwan(int cs) {
    cin >> n >> q;
    v.assign(n, 0);
    for (auto &vl : v)
        cin >> vl;

    while (q--) {
        cin >> d >> m;
        if (d == 0 || m == 0) {
            cout << 0 << endl;
            continue;
        }
        dp.assign(n, vector<vector<int>>(m, vector<int>(d, -1)));
        cout << f(0, 0, 0) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}