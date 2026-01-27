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
void dfs(int n, vector<int> &v, vector<int> g[], vector<int> &vis, int xr, vector<int> &s)
{
    vis[n] = 1;
    s.push_back(n);
    for (auto child : g[n])
    {
        if (!vis[child])
        {
            dfs(child, v, g, vis, xr, s);
        }
    }
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1, 0), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int xr = 0ll;
    for (int i = 1; i <= n; i++)
    {
        map<int, int> fnd;
        fnd[0] = -1;
        if (!vis[i])
        {
            xr = 0ll;
            vector<int> s;
            dfs(i, v, g, vis, xr, s);
            for (int i = 0; i < s.size(); i++)
            {
                xr ^= v[s[i]];
                if (fnd.find(k ^ xr) != fnd.end())
                {
                    yes;
                    cout << i - fnd[k ^ xr] << endl;
                    for (int j = fnd[k ^ xr] + 1; j <= i; j++)
                        cout << s[j] << " ";
                    cout << endl;
                    return;
                }
                fnd[xr] = i;
            }
        }
    }
    no;
    // cerr << endl;
    // cout << endl;
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