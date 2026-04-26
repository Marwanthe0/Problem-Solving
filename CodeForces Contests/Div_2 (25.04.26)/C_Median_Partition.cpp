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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> t = v;
    sort(all(t));
    int m = t[n / 2];
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int chuto = 0, boro = 0, eq = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (v[j] < m)
                chuto++;
            else if (v[j] == m)
                eq++;
            else
                boro++;
            if ((i - j) % 2 == 0)
                continue;
            if (chuto + eq > boro && boro + eq > chuto) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << dp[n] << endl;
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