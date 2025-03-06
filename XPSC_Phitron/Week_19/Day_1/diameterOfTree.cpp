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
vector<int> g[N], height(N, 0);
void dfs(int n, int par = -1)
{
    for (auto child : g[n])
    {
        if (par == child)
            continue;
        height[child] = height[n] + 1;
        dfs(child, n);
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
    int mx = INT_MIN, mxidx;
    for (int i = 1; i <= n; i++)
    {
        if (height[i] > mx)
        {
            mx = height[i];
            mxidx = i;
        }
        height[n] = 0;
    }
    dfs(mxidx);
    mx = INT_MIN;
    int mnidx;
    for (int i = 1; i <= n; i++)
    {
        if (height[i] > mx)
        {
            mx = height[i];
            mnidx = i;
        }
        height[n] = 0;
    }
    cout << mxidx << " " << mnidx << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}