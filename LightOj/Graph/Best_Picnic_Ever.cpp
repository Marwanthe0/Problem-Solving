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
int n, k, m;
vector<vector<int>> g;
vector<int> vis, cnt, ks;
void marwan(int cs) {

    cin >> k >> n >> m;
    ks.assign(k, 0);
    g.assign(n + 1, vector<int>());
    cnt.assign(n + 1, 0);
    vector<int> loaction_city;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        loaction_city.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    auto bfs = [&](int src) {
        queue<int> q;
        vector<bool> ok(n + 1, false);

        q.push(src);
        cnt[src]++;
        ok[src] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (!ok[v]) {
                    ok[v] = true;
                    cnt[v]++;
                    q.push(v);
                }
            }
        }
    };
   for (int i : loaction_city) {
       bfs(i);
   }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        // cerr << i << " " << cnt[i] << endl;
        ans += (cnt[i] >= k);
    }
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