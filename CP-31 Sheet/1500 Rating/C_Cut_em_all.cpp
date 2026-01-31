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
void marwan()
{

    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> vis(n + 1, 0), par(n + 1), sz(n + 1, 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n & 1)
    {
        minus;
        return;
    }
    auto dfs = [&](auto &&dfs, int src, int pr) -> void
    {
        vis[src] = true;
        par[src] = pr;
        for (auto child : g[src])
        {
            if (!vis[child])
            {
                dfs(dfs, child, src);
                sz[src] += sz[child];
            }
        }
    };
    dfs(dfs, 1, 0);
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (sz[i] % 2 == 0)
            count++;
        // cout << i << " " << par[i] << " " << sz[i] << endl;
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}