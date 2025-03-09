#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int n;
int a1, a2, b1, b2, c1, c2;
bool vis[1005][1005];
bool ans = false;
vector<pair<int, int>> path = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
bool valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}
void dfs2(int i, int j, vector<vector<char>> &g)
{
    vis[i][j] = true;
    g[i][j] = 'A';
    if (i == c1 && j == c2)
        ans = true;
    for (int k = 0; k < 8; k++)
    {
        int ci = i + path[k].first;
        int cj = j + path[k].second;
        if (valid(ci, cj) && !vis[ci][cj] && g[ci][cj] != '*')
        {
            dfs2(ci, cj, g);
        }
    }
}
void dfs(int i, int j, int x, int y, vector<vector<char>> &g)
{

    vis[i][j] = true;
    g[i][j] = '*';
    int ci = i + x;
    int cj = j + y;
    if (valid(ci, cj) && !vis[ci][cj])
    {
        dfs(ci, cj, x, y, g);
    }
}
void marwan()
{
    memset(vis, false, sizeof(vis));
    cin >> n;
    vector<vector<char>> g(n, vector<char>(n));
    // vector<vector<int>> g(vector<int>(n));
    cin >> a1 >> a2;
    a1--, a2--;
    for (int k = 0; k < 8; k++)
    {
        int x = path[k].first;
        int y = path[k].second;
        dfs(a1, a2, x, y, g);
    }
    cin >> b1 >> b2;
    b1--, b2--;
    cin >> c1 >> c2;
    c1--, c2--;
    dfs2(b1, b2, g);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] != '*' && g[i][j] != 'A')
                g[i][j] = '.';
        }
    }
    if (ans)
        yes;
    else
        no;
}
int main()
{
    marwan();
    return 0;
}