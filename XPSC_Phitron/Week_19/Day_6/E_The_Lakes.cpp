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
bool vis[1005][1005];
int n, m, sum = 0;
vector<pair<int, int>> path = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
void dfs(vector<vector<int>> &v, int i, int j)
{
    vis[i][j] = true;
    sum += v[i][j];
    for (int k = 0; k < 4; k++)
    {
        int ci = i + path[k].first;
        int cj = j + path[k].second;
        if (valid(ci, cj) && vis[ci][cj] == false && v[ci][cj] != 0)
        {
            dfs(v, ci, cj);
        }
    }
}
void marwan()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            vis[i][j] = false;
    }
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum = 0;
            if (vis[i][j] == false && a[i][j] > 0)
            {
                dfs(a, i, j);
                ans = max(ans, sum);
            }
        }
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