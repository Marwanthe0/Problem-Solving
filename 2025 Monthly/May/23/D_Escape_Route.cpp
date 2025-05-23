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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<pair<int, int>> em;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'E')
                em.push_back({i, j});
        }
    }
    for (auto vl : em)
        cerr << vl.first << " " << vl.second << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#' || v[i][j] == 'E')
            {
                cout << v[i][j];
                continue;
            }
            int dt = INT_MAX, d1, d2;
            for (auto vl : em)
            {
                if (abs(i - vl.first) + abs(j - vl.second) < dt)
                {
                    dt = abs(i - vl.first) + abs(j - vl.second), d1 = vl.first, d2 = vl.second;
                }
            }
            // if (d1 == i)
            // {
            //     if (d2 > j)
            //         cout << ">";
            //     else
            //         cout << "<";
            // }
            // else if (d2 == j)
            // {
            //     if (d1 > i)
            //         cout << "v" << endl;
            //     else
            //         cout << "^";
            // }
            // else
            // cout << '.';
            cout << d1 << d2 << " ";
        }
        cout << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}