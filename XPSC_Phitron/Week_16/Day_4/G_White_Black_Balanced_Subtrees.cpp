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
int ans = 0;
vector<bool> check;
vector<vector<int>> g;
vector<int> v;
string s;
pair<int, int> dfs(int root)
{
    if (check[root])
    {
        return {0, 0};
    }
    int b = 0, w = 0;
    check[root] = true;
    if (s[root] == 'B')
        b++;
    else
        w++;
    for (int i = 0; i < g[root].size(); i++)
    {
        if (!check[g[root][i]])
        {
            pair<int, int> val = dfs(g[root][i]);
            b += val.first, w += val.second;
        }
    }
    if (b == w)
        ans++;
    return {b, w};
}
void marwan()
{
    int n;
    cin >> n;
    g.resize(n + 2);
    v.resize(n + 2);
    check.resize(n + 2, false);
    for (int i = 2; i <= n; i++)
    {
        cin >> v[i];
        // cout << v[i] << " ";
        g[i].push_back(v[i]);
        g[v[i]].push_back(i);
    }
    cin >> s;
    s = "0" + s;
    dfs(1);
    cout << ans << endl;
    check.clear();
    g.clear(), v.clear();
    ans = 0;
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