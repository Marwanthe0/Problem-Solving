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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int dp[N][11][1025];
int f(int i, int count, vector<int> &v, vector<int> &a, int k, int mask) {
    if (count > k)
        return -1e17;
    if (i == v.size() && mask == (1 << a.size()) - 1)
        return 0;
    int pos = (i - count + __builtin_popcount(mask));
    if (dp[i][count][mask] != -1e17)
        return dp[i][count][mask];
    int nimu = -1e17, nitamna = -1e17;
    if (i < v.size())
        nimu = f(i + 1, count, v, a, k, mask) + (v[i] * pos);
    if (i < v.size())
        nitamna = f(i + 1, count + 1, v, a, k, mask);
    for (int idx = 0; idx < a.size(); idx++) {
        if (!(1 & (mask >> idx))) {
            nimu = max(nimu, f(i, count, v, a, k, mask | (1 << idx)) + (a[idx] * pos));
        }
    }
    return dp[i][count][mask] = max(nimu, nitamna);
}
void marwan() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + 1), a(m);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (auto &vl : a)
        cin >> vl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= (1 << m); l++)
                dp[i][j][l] = -1e17;
        }
    }
    int ans = f(1, 0, v, a, k, 0);
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