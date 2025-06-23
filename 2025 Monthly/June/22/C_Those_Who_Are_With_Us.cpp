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
    int n, m, mx = INT_MIN;
    cin >> n >> m;
    int a[n][m], c[n][m], x[n], y[m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    int app = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == mx)
                app++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == mx)
                count++;
        }
        x[i] = count;
    }
    for (int j = 0; j < m; j++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == mx)
                count++;
        }
        y[j] = count;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if ((x[i] + y[j] + ((a[i][j] == mx ? -1 : 0))) == app)
            {
                cout << mx - 1 << endl;
                return;
            }
    }
    cout << mx << endl;
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