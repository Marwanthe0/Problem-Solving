#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k, m;
    cin >> n >> m >> k;
    vector<pair<int, int>> v;
    vector<int> t(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int c, val;
        cin >> c >> val;
        v.push_back({val, c});
        t[c] = max(t[c], val);
    }
    sort(all(t), greater<int>());
    sort(all(v));
    reverse(all(v));
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += t[i];
    }
    m -= k;
    vector<bool> vis(n + 1, 0);
    int ccount = 0;
    for (int i = 0, j = 0; i < m && j < v.size(); i++, j++) {
        int val = v[j].first, col = v[j].second;
        if (ccount < k && !vis[col]) {
            vis[col] = 1;
            ccount++;
            i--;
            continue;
        }
        ans += val;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}