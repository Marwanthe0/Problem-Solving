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
vector<pair<int, int>> path = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
string pn = "RLUD";
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    pair<int, int> s, d;
    string ans;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
                s = {i, j};
            if (v[i][j] == 'B')
                d = {i, j};
        }
    }
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));
    // cerr << s.first << " " << s.second << " " << d.first << " " << d.second << endl;
    vector<vector<int>>
        vis(n, vector<int>(m, 0));
    bool flag = false;
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second] = 1ll;
    par[s.first][s.second] = {-1ll, -1ll};
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        if (make_pair(i, j) == d)
        {
            flag = true;
            break;
        }
        for (auto [x, y] : path)
        {
            x += i, y += j;
            if (x >= 0 && x < v.size() && y >= 0 && y < v[0].size() && v[x][y] != '#' && vis[x][y] == 0)
            {
                q.push({x, y});
                vis[x][y] = 1;
                par[x][y] = {i, j};
            }
        }
    }
    if (!flag)
    {
        no;
        return;
    }
    yes;
    auto cur = par[d.first][d.second];
    int idx = 0;
    for (auto [x, y] : path)
    {
        x += par[d.first][d.second].first, y += par[d.first][d.second].second;
        if (make_pair(x, y) == d)
        {
            ans.push_back(pn[idx]);
        }
        idx++;
    }
    while (cur != make_pair(-1ll, -1ll))
    {
        idx = 0;
        for (auto [x, y] : path)
        {
            x += par[cur.first][cur.second].first, y += par[cur.first][cur.second].second;
            if (make_pair(x, y) == cur)
            {
                ans.push_back(pn[idx]);
            }
            idx++;
        }
        cur = par[cur.first][cur.second];
    }
    cout << ans.size() << endl;
    reverse(all(ans));
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}