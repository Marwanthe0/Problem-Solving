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
bool bfs(int src, vector<vector<int>> &g, vector<int> &vis)
{
    int sz = 0;
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        sz++;
        for (auto child : g[nd])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
    return sz & 1;
}
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<int> vis(n + 1), par(n + 1, -1);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
            flag = false;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (!flag)
    {
        no;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() != 2)
        {
            no;
            return;
        }
        if (!vis[i])
        {
            if (bfs(i, g, vis))
            {
                no;
                return;
            }
        }
    }
    yes;
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