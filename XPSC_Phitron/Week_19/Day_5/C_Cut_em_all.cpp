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
vector<int> g[N];
int x = 0;
vector<int> vis(N, 0), sub_sum(N, 0);
void dfs(int n, int par, int sum)
{
    sub_sum[n]++;
    for (auto child : g[n])
    {
        if (child == par)
            continue;
        dfs(child, n, sum);
        sub_sum[n] += sub_sum[child];
    }
    if ((sum - sub_sum[n]) % 2 == 0 && sum != sub_sum[n])
        x++;
}
void marwan()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    dfs(1, -1, n);
    cout << x << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}