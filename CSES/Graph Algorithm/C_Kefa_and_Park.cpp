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
vector<vector<int>> g;
vector<int> v, vis;
set<int> leaves;
int dfs(int n, int c, int k)
{
    if (leaves.count(n) && c <= k)
        return 1;
    vis[n] = 1;
    int count = 0;
    for (auto child : g[n])
    {
        if (vis[child] == 0 && c <= k)
        {
            count += dfs(child, v[child] ? c + v[child] : 0, k);
        }
    }
    return count;
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    v.resize(n + 1);
    vis.resize(n + 1);
    g.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 2; i <= n; i++)
    {
        if (g[i].size() == 1)
        {
            leaves.insert(i);
        }
    }
    cout << dfs(1, v[1], k);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}