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
void bfs(int src, vector<vector<int>> &g, vector<int> &lvl, vector<int> &par)
{
    queue<int> q;
    vector<int> vis(g.size() + 1, 0);
    q.push(src);
    vis[src] = 1;
    lvl[src] = 0;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        vis[nd] = 1;
        for (auto child : g[nd])
        {
            if (!vis[child])
            {
                q.push(child);
                lvl[child] = lvl[nd] + 1;
                par[child] = nd;
            }
        }
    }
}
int dfs(int src, vector<vector<int>> &g, vector<int> &v, vector<int> &vis, vector<int> &val)
{
    vis[src] = 1;
    int vl = v[src];
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            vl += dfs(child, g, v, vis, val);
        }
    }
    return val[src] = vl;
}
int dfs2(int src, vector<vector<int>> &g, vector<int> &lvl, vector<int> &vis, int cond)
{
    vis[src] = 1;
    int cur = src;
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            if (child != cond)
            {
                int x = dfs2(child, g, lvl, vis, cond);
                if (lvl[x] > lvl[cur])
                    cur = x;
            }
        }
    }
    // cerr << src << " " << cur << endl;
    return cur;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    vector<int> lvl(n + 1), val(n + 1), vis(n + 1, 0), par(n + 1, -1);
    bfs(1, g, lvl, par);
    int x = dfs(1, g, v, vis, val);
    // for (int i = 1; i <= n; i++)
    //     cout << val[i] << " ";
    int mx = -1;
    for (int i = 2; i <= n; i++)
    {
        if (g[par[i]].size() > 2 || (par[i] == 1 && g[par[i]].size() > 1))
        {
            if (val[i] >= mx)
                mx = i;
        }
    }
    if (mx != -1)
    {
        for (int i = 1; i <= n; i++)
            cerr << lvl[i] << " ";
        cerr << endl;
        vis.assign(n + 1, 0);
        int tmx = dfs2(1, g, lvl, vis, mx);
        cout << mx << " " << tmx << endl;
        auto it = g[mx].begin(), tt = g[par[mx]].begin();
        while (*it != par[mx])
            it++;
        while (*tt != mx)
            tt++;
        g[mx].erase(it);
        g[par[mx]].erase(it);
        g[mx].push_back(tmx);
        g[tmx].push_back(mx);
        lvl.assign(n + 1, 0), val.assign(n + 1, 0), vis.assign(n + 1, 0), par.assign(n + 1, -1);
        bfs(1, g, lvl, par);
        // int x = dfs(1, g, v, vis, val);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}