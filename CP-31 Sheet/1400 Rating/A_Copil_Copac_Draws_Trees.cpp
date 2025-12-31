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
void bfs(vector<int> g[], map<pair<int, int>, int> &m, int src, vector<bool> &vis, vector<int> &par, vector<int> &as)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    par[src] = 0;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        vis[f] = true;
        // cerr << f << " ";
        if ((as[f] != 1) && (m[{min(f, par[f]), max(f, par[f])}] > m[{min(par[f], par[par[f]]), max(par[f], par[par[f]])}]))
        {
            as[f] = as[par[f]];
        }
        else if (as[f] != 1)
            as[f] = as[par[f]] + 1;
        for (auto vl : g[f])
        {
            if (!vis[vl])
            {
                par[vl] = f;
                vis[vl] = true;
                q.push(vl);
            }
        }
    }
    // cerr << endl;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> g[n + 1];
    map<pair<int, int>, int> m;
    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        g[a].push_back(b);
        g[b].push_back(a);
        m[{min(a, b), max(a, b)}] = i;
    }
    vector<bool> vis(n + 1);
    vector<int> par(n + 1), as(n + 1, 1);
    set<int> check = {1};
    for (int i = 0; i < n - 1; i++)
    {
        int l = v[i].first, r = v[i].second;
        if (check.find(l) != check.end())
        {
            check.insert(l);
            check.insert(r);
            as[l] = 1, as[r] = 1;
        }
        if (check.find(r) != check.end())
        {
            check.insert(l);
            check.insert(r);
            as[l] = 1, as[r] = 1;
        }
        if (check.find(l) == check.end() && check.find(r) == check.end())
            as[l] = -1, as[r] = -1;
    }
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    bfs(g, m, 1, vis, par, as);
    for (int i = 1; i <= n; i++)
    {
        int f = i;
        // cerr << i << " " << par[i] << " " << as[i] << " " << as[par[i]] << endl;
        if ((as[f] != 1) && (m[{min(f, par[f]), max(f, par[f])}] > m[{min(par[f], par[par[f]]), max(par[f], par[par[f]])}]))
        {
            as[f] = as[par[f]];
        }
        else if (as[f] != 1)
            as[f] = as[par[f]] + 1;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << as[i] << " ";
    // cout << endl;
    cout << *max_element(all(as)) << endl;
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