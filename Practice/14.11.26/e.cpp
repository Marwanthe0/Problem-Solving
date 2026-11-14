#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 3000005
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
vector<pair<int, int>> vis;
void marwan(int cs) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        int nd = v[i], j = i - 1;
        for (j = i - 1; j >= 0; j--) {
            nd &= v[j];
            if (vis[nd].first > 0) {
                cout << j + 1 << " " << i + 1 << " " << vis[nd].second + 1 << endl;
                for (auto vl : v) {
                    vis[vl ^ k].first = 0,
                             vis[vl ^ k].second = 0;
                }
                return;
            }
            if (nd == 0) {
                break;
            }
        }
        vis[v[i] ^ k].first++, vis[v[i] ^ k].second = i;
    }
    minus;
    for (auto vl : v) {
        vis[vl ^ k].first = 0,
                 vis[vl ^ k].second = 0;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vis.assign(N + 1, {0, 0});
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}