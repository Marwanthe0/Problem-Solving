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
    int n, k;
    cin >> n >> k;
    char a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    char x[n / k][n / k];
    for (int i = 0; i < n; i += k)
    {
        for (int j = 0; j < n; j++)
        {
            x[i / k][j / k] = a[i][j];
        }
    }
    for (int i = 0; i < n / k; i++)
    {
        for (int j = 0; j < n / k; j++)
            cout << x[i][j];
        cout << endl;
    }
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