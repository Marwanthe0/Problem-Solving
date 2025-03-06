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
vector<int> g[N], sum(N, 0), even(N, 0);
void dfs(int n, int par = -1)
{
    cerr << n << endl;
    sum[n] = n;
    even[n] += ((n & 1) == 0);
    for (auto child : g[n])
    {
        if (child == par)
            continue;
        dfs(child, n);
        even[n] += even[child] + (n & 1 == 0);
        sum[n] += sum[child];
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
        cout << sum[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << even[i] << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}