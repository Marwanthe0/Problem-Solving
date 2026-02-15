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
int dfs(int src, vector<vector<int>> &g, vector<int> &val, vector<int> &vis, vector<int> &childs)
{
    vis[src] = 1;
    int nd = 1;
    for (auto child : g[src])
    {
        if (!vis[child])
            nd += dfs(child, g, val, vis, childs);
    }
    return childs[src] = nd;
}
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    vector<int> val(n + 1, 1), vis(n + 1, 0), childs(n + 1, 0), vis2(n + 1, 0), parent(n + 1, -1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (v[i].first)
        {
            g[i].push_back(v[i].first);
            g[v[i].first].push_back(i);
        }
        if (v[i].second)
        {
            g[i].push_back(v[i].second);
            g[v[i].second].push_back(i);
        }
    }
    dfs(1, g, val, vis, childs);
    for (int i = 1; i <= n; i++)
    {
        childs[i]--;
        val[i] += childs[i] * 2;
        // cout << childs[i] << " " << val[i] << endl;
    }
    queue<int> q;
    q.push(1);
    vis2[1] = 1;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        vis2[nd] = 1;
        for (auto child : g[nd])
        {
            if (!vis2[child])
            {
                val[child] += val[nd];
                q.push(child);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << (val[i] % M) << " ";
    cout << endl;
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