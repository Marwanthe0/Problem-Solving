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
vector<int> g[N], parent(N, 0);
void dfs(int n, int par = -1)
{
    for (auto child : g[n])
    {
        if (child == par)
            continue;
        parent[child] = n;
        dfs(child, n);
    }
}
vector<int> path(int n)
{
    vector<int> ans;
    while (n != 0)
    {
        ans.push_back(n);
        n = parent[n];
    }
    reverse(all(ans));
    return ans;
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
    int node1, node2;
    cin >> node1 >> node2;
    dfs(1);
    // for (int i = 1; i <= n; i++)
    //     cout << parent[i] << " ";
    // cout << endl;
    vector<int> a = path(node1), b = path(node2);
    int l = 0;
    while (a[l] == b[l])
        l++;
    cout << a[l - 1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}