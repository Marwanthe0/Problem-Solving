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
    int n, x, y;
    cin >> n >> x >> y;
    vector<pair<int, int>> a, v;
    map<int, map<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        int vl;
        cin >> vl;
        int val = vl % x;
        m[vl % y][vl % x]++;
        if (val <= x / 2)
        {
            a.push_back({val, vl % y});
            // cout << a.back().first << " " << a.back().second << endl;
        }
        else
        {
            v.push_back({val, vl % y});
            // cout << v.back().first << " " << v.back().second << endl;
        }
    }
    int ans = 0;
    for (auto vl : m)
    {
        set<int> check;
        for (auto val : vl.second)
        {
            if (check.find(val.first) != check.end())
                continue;
            if (val.first == 0)
            {
                ans += (val.second * (val.second - 1)) / 2;
                continue;
            }
            if ((x % 2 == 0) && (val.first == x / 2))
            {
                ans += (val.second * (val.second - 1)) / 2;
                continue;
            }
            if (vl.second.find(x - val.first) != vl.second.end())
            {
                ans += (val.second * vl.second[x - val.first]);
                cerr << val.second << " " << vl.second[x - val.first] << endl;
                check.insert(x - val.first);
            }
        }
    }
    cout << ans << endl;
    // cout << endl;
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