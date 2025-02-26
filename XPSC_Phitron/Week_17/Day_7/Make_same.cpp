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
    string a, b, c;
    cin >> a >> b >> c;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
            x++;
        if (b[i] == '1')
            y++;
        if (c[i] == '1')
            z++;
    }
    cerr << x << y << z << endl;
    if ((x + y + z) % n != 0)
    {
        cout << -1 << endl;
        return;
    }
    // int mx = max({x, y, z, n - x, n - y, n - z});
    // if (mx == n)
    // {
    //     if (x == 0 || x == n)
    //         cout << min(y, z) << endl;
    //     else if (y == 0 || y == n)
    //         cout << min(x, z) << endl;
    //     else
    //         cout << min(x, y) << endl;
    // }
    // else
    // {
        x = min(x, n - x), y = min(y, n - y), z = min(z, n - z);
        cout << (x + y + z) - max({x, y, z}) << endl;
    // }
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