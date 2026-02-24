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
    vector<int> vis(n + 1, 0), par(n + 1);
    queue<int> q;
    q.push(1);
    par[1] = -1;
    bool flag = false;
    vis[1] = 1;
    while (!q.empty())
    {
        int nd = q.front();
        q.pop();
        if (nd == n)
        {
            flag = true;
            break;
        }
        for (auto child : g[nd])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                q.push(child);
                par[child] = nd;
            }
        }
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int x = par[n];
    vector<int> ans = {n};
    while (x != -1)
    {
        ans.push_back(x);
        x = par[x];
    }
    cout << ans.size() << endl;
    reverse(all(ans));
    for (auto vl : ans)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}