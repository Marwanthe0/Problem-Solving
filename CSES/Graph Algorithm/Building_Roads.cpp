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
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int find(int x, vector<int> &par)
{
    return par[x] == x ? x : par[x] = find(par[x], par);
}
void dsunion(int a, int b, vector<int> &par)
{
    a = find(a, par), b = find(b, par);
    if (a > b)
        swap(a, b);
    if (a != b)
    {
        par[b] = par[a];
    }
}
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> par(n + 1), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        dsunion(u, v, par);
    }
    vector<int> leader;
    for (int i = 1; i <= n; i++)
    {
        par[i] = find(i, par);
        leader.push_back(par[i]);
    }
    make_unique(leader);
    cout << leader.size() - 1 << endl;
    if (leader.size() > 1)
    {
        for (int i = 1; i < leader.size(); i++)
            cout << leader[i] << " " << leader[i - 1] << endl;
        cout << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}