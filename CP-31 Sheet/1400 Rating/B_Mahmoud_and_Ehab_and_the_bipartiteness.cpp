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
void bfs(vector<int> g[], int src, vector<int> &vis, vector<int> &clr)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    clr[src] = 1;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : g[par])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                clr[child] = (!clr[par]);
                q.push(child);
            }
        }
    }
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> g[n + 1], clr(n + 1, -1), vis(n + 1, 0);
    multiset<pair<int, int>> ms;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        ms.insert({u, v});
        ms.insert({v, u});
    }
    bfs(g, 1, vis, clr);
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++)
    {
        m[clr[i]].push_back(i);
    }
    cout << (m[0].size() * m[1].size()) - (n - 1) << endl;
    // cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}