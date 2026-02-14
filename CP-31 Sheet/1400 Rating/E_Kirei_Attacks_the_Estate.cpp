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
    vector<int> v(n + 1), parent(n + 1, -1), vis(n + 1, 0), ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    ans[1] = v[1];
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        vis[par] = 1;
        for (auto child : g[par])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                parent[child] = par;
                q.push(child);
                ans[child] = max(v[child], (v[child] - v[parent[child]]) + (par != 1 ? ans[parent[par]] : 0));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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