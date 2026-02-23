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
void marwan()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &s : v)
        cin >> s;
    queue<pair<int, int>> q;
    q.push({0, 0});
    string ans;
    ans.push_back(v[0][0]);
    vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
    if (n == 1)
    {
        cout << v[0][0] << endl;
        return;
    }
    while (1)
    {
        char mn = 'Z';
        bool flag = false;
        vector<pair<int, int>> cand;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if (x < n - 1)
            {
                if (!vis[x + 1][y])
                {
                    cand.push_back({x + 1, y});
                    mn = min(mn, v[x + 1][y]);
                    vis[x + 1][y] = 1;
                }
            }
            if (y < n - 1)
            {
                if (!vis[x][y + 1])
                {
                    cand.push_back({x, y + 1});
                    mn = min(mn, v[x][y + 1]);
                    vis[x][y + 1] = 1;
                }
            }
        }
        for (auto &[x, y] : cand)
            if (v[x][y] == mn)
            {
                q.push({x, y});
                if (x == n - 1 && y == n - 1)
                    flag = true;
            }
        ans.push_back(mn);
        if (flag)
        {
            break;
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}