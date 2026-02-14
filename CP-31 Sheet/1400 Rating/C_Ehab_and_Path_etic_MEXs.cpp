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
    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
        v.push_back({a, b});
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() >= 3 && flag)
        {
            flag = false;
            int xi = 0, yi = 3;
            for (auto [x, y] : v)
            {
                if ((x == i || y == i) && xi < 3)
                {
                    cout << xi++ << endl;
                }
                else
                    cout << yi++ << endl;
            }
        }
    }
    if (flag)
    {
        int xi = 0;
        for (auto [x, y] : v)
            cout << xi++ << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}