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
    vector<int> v, vis(n + 1, 0);
    for (int i = 2; i < n; i++)
    {
        v.push_back(1 ^ i);
        vis[1 ^ i] = 1;
        // cout << (n ^ i) << " ";
    }
    vis[1] = 1;
    v.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if ((i ^ 1) <= n && vis[i ^ 1])
            {
                cout << i << " ";
                break;
            }
            else
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int, vector<pair<int, int>>> m;
    for (int i = 2; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            m[i ^ j].push_back({i, j});
        }
    }
    for (auto [x, v] : m)
    {
        cout << x << endl;
        for (auto [i, j] : v)
            cout << i << " " << j << endl;
        cout << endl;
    }
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     marwan();
    // }
    return 0;
}