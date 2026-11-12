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
int n, m;
vector<int> a, b;
void marwan(int cs) {
    cin >> n >> m;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;
    sort(all(v));

    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    vector<int> used(m + 1, 0);
    for (int i = 0; i < n; i++) {
        used.assign(m + 1, 0);
        for (int j = v[i].first; j <= m; j++) {
            
            if (dp[j] == 0 && dp[j - v[i].first] && used[j - v[i].first] < v[i].second) {
                dp[j] = 1;
                used[j] = used[j - v[i].first] + 1;
            }
        }
    }
    cout << accumulate(all(dp), 0ll) - 1 << endl;
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