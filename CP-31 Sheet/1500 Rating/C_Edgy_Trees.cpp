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
long long modpow(long long a, long long b)
{
    long long res = 1;
    a %= M;
    while (b)
    {
        if (b & 1)
            res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

void dfs(int src, vector<int> g[], vector<int> &vis, int &cnt)
{
    cnt++;
    vis[src] = 1;
    // cerr << src << " ";
    for (auto child : g[src])
    {
        if (!vis[child])
            dfs(child, g, vis, cnt);
    }
}
void marwan()
{
    int n, k;
    cin >> n >> k;
    int x = modpow(n, k);
    vector<int> g[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (!c)
        {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && g[i].size())
        {
            int cnt = 0;
            dfs(i, g, vis, cnt);
            // cerr << cnt << " ";
            x = (x - modpow(cnt, k) + M) % M;
            // cerr << endl;
        }
        else if (!vis[i] && g[i].empty())
            x = (x - 1 + M) % M;
    }
    cout << x << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}