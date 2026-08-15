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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    int total = 0, mx = 0, end = 0;
    vector<int> vis(3 * n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[v[i]]) {
            vis[v[i]]++;
            end = max(end, v[i] + 1);
        } else {
            int x = max(end, v[i]);
            while (vis[x]) {
                x++;
            }
            vis[x]++;
            end = max(end, x + 1);
            mx = max(mx, x - v[i]);
            total += x - v[i];
        }
    }
    // cout << mx << " " << total << endl;
    cout << max(mx, (total) / k + ((total % k) != 0)) << endl;
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