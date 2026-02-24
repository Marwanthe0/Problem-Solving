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
vector<pair<int, int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void dfs(int i, int j, vector<string> &v, vector<vector<int>> &vis)
{
    vis[i][j] = 1;
    for (auto [x, y] : path)
    {
        x += i, y += j;
        if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size() && v[x][y] == '.' && vis[x][y] == 0)
            dfs(x, y, v, vis);
    }
}
void marwan()
{
    int n, m, count = 0ll;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && v[i][j] == '.')
            {
                dfs(i, j, v, vis);
                count++;
            }
        }
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}