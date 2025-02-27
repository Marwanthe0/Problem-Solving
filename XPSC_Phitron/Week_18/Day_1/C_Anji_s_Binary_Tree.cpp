#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 300009
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
string s;
vector<int> g[N], op(N);
void dfs(int root)
{
    if (g[root][0])
    {
        if (s[root - 1] != 'L')
            op[g[root][0]] = op[root] + 1;
        else
            op[g[root][0]] = op[root];
        dfs(g[root][0]);
    }
    if (g[root][1])
    {
        if (s[root - 1] != 'R')
            op[g[root][1]] = op[root] + 1;
        else
            op[g[root][1]] = op[root];
        dfs(g[root][1]);
    }
}
void marwan()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
        op[i] = 0;
    }
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[i].push_back(a);
        g[i].push_back(b);
    }
    dfs(1);
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (g[i][0] == 0 && g[i][1] == 0)
            ans = min(ans, op[i]);
    }
    cout << ans << endl;
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