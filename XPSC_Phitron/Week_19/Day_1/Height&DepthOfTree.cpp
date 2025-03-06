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
vector<int> g[N], height(N, 0), depth(N, 0);
void dfs(int n, int par = -1)
{
    for (auto child : g[n])
    {
        if (par == child)
            continue;
        height[child] = height[n] + 1;
        dfs(child, n);
        depth[n] = max(depth[n], depth[child] + 1);
    }
}
void marwan()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << height[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << depth[i] << " ";
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