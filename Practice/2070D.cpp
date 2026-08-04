#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
int n;
vector<vector<int>> g;
vector<int> level, vis, ans, cnt, tans;
void bfs(int src) {
    queue<int> q;
    vis.assign(n + 1, 0);
    q.push(src);
    vis[src] = 1;
    while (!q.empty()) {
        int nd = q.front();
        // cout << nd << "::" << level[nd] << endl;
        // Number of nodes per level
        cnt[level[nd]]++;
        int l = level[nd], l1 = level[nd] - 1;
        if (l <= 1)
            ans[l]++, tans[l] = 1;
        else {
            tans[l] = ((cnt[l1] - 1) * 1ll * tans[l1]) % M;
            ans[l] = (ans[l] + tans[l]);
        }
        ans[l] %= M;
        q.pop();
        for (auto child : g[nd]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1;
                // level of each node.
                level[child] = level[nd] + 1;
            }
        }
    }
    // cout << endl;
}
void marwan() {
    cin >> n;
    g.assign(n + 1, vector<int>());
    level.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    tans.assign(n + 1, 0);
    cnt.assign(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    bfs(1);
    int mxlevel = 0;
    for (int i = 1; i <= n; i++) {
        // cout << i << " " << level[i] << endl;
        mxlevel = max(mxlevel, level[i]);
    }
    int uttor = 0ll;
    for (int i = 0; i <= mxlevel; i++) {
        // cout << i << " " << cnt[i] << " " << ans[i] << endl;
        uttor = (uttor + (ans[i] % M)) % M;
    }
    cout << uttor << endl;
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