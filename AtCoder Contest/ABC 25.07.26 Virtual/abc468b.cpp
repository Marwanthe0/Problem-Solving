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
void marwan() {
    int m, d;
    cin >> m >> d;
    string s;
    cin >> s;
    vector<int> dist(m, INT_MAX);
    for (int i = 0; i < m; i++) {
        if (s[i] == 'G')
            dist[i] = 0;
        else if (i)
            dist[i] = min(dist[i], dist[i - 1] + 1);
    }
    int ans = 0ll;
    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == 'G')
            dist[i] = 0;
        else if (i != m - 1)
            dist[i] = min(dist[i], dist[i + 1] + 1);
        if (dist[i] > d)
            ans++;
    }
    // for (auto vl : dist)
    //     cout << vl << " ";
    // cout << endl;
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while (t--) {
    //     marwan();
    // }
    marwan();
    return 0;
}