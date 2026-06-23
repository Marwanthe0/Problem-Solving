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
int n, m;
bool flag = true;
int a = 0, b = 0;
vector<vector<int>> g;
vector<int> vis, color;
void dfs(int v, bool c) {
    vis[v] = 1;
    color[v] = c;
    if (c)
        a++;
    else
        b++;
    for (auto &child : g[v]) {
        if (vis[child] && color[child] == color[v]) {
            flag = false;
        }
        if (!vis[child]) {
            dfs(child, !c);
        }
    }
}
void marwan() {
    cin >> n >> m;
    flag = true;
    g.assign(n + 1, vector<int>());
    vis.assign(n + 1, 0);
    color.assign(n + 1, -1);
    unordered_set<int> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(x);
        s.insert(y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 1ll;
    auto pw = [&](int a) {
        int x = 1ll;
        for (int i = 0; i < a; i++) {
            x = (x * 2ll) % M;
        }
        return x % M;
    };
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && s.count(i)) {
            a = 0, b = 0;
            dfs(i, 0);
            // cerr << pw(a) << " " << pw(b) << endl;
            int tans = (pw(a) + pw(b)) % M;
            ans = (ans * 1ll * tans) % M;
        } else if (!vis[i])
            ans = (ans * 3ll) % M;
        // cerr << ans << endl;
    }
    if (flag)
        cout << ans << endl;
    else
        zero;
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