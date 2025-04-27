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
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &row : v)
    {
        for (auto &vl : row)
            cin >> vl;
    }
    // for (auto row : v)
    // {
    //     for (auto vl : row)
    //         cout << vl << "  ";
    //     cout << endl;
    // }
    // cout << endl;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = 0, y = i, mx = 0;
        while (x < n && y < n)
        {
            if (v[x][y] < 0)
                mx = max(mx, abs(v[x][y]));
            x++,
                y++;
        }
        ans += mx;
    }
    for (int i = 1; i < n; i++)
    {
        int x = i, y = 0, mx = 0;
        while (x < n && y < n)
        {
            if (v[x][y] < 0)
                mx = max(mx, abs(v[x][y]));
            x++,
                y++;
        }
        ans += mx;
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