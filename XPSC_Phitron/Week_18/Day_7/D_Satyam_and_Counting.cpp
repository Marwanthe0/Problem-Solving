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
    vector<pair<int, int>> v;
    map<int, int> m;
    vector<vector<int>> vis(n + 5, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        vis[x][y]++;
        m[x]++;
    }
    int ans = 0;
    for (auto vl : m)
    {
        if (vl.second > 1)
        {
            ans += (n - 2);
        }
    }
    cerr << ans << endl;
    for (auto [x, y] : v)
    {
        if (vis[x + 1][1 - y] && vis[x + 2][y])
            ans++;
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
