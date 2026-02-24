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
bool dfs(int src, vector<vector<int>> &g, vector<int> &vis, vector<int> &ans)
{
    vis[src] = 1;
    bool flag = true;
    for (auto child : g[src])
    {
        int color = !ans[src];
        if (vis[child] && ans[child] == ans[src])
        {
            flag = false;
        }
        else if (!vis[child])
        {
            ans[child] = color;
            flag = flag & dfs(child, g, vis, ans);
        }
    }
    return flag;
}
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), par(n + 1, -1), ans(n + 1, -1);
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans[i] = 0;
            flag = flag & dfs(i, g, vis, ans);
        }
    }
    if (!flag)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << ans[i] + 1 << " ";
        cout << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}