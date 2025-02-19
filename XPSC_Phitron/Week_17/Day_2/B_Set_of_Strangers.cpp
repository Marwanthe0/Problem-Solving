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
    int a[n][m];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mp[a[i][j]]++;
        }
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] == a[i][j - 1])
            {
                s.insert(a[i][j]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[j][i] == a[j - 1][i])
            {
                s.insert(a[j][i]);
            }
        }
    }
    if (s.size())
        cout << (mp.size() - 1) + s.size() - 1 << endl;
    else
        cout << (mp.size() - 1) << endl;
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