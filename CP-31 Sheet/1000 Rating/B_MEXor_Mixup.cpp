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
    int a, x;
    cin >> a >> x;
    int ans = a;
    int xr = 0;
    switch ((a - 1) % 4)
    {
    case 0:
        xr = a - 1;
        break;
    case 1:
        xr = 1;
        break;
    case 2:
        xr = a;
        break;
    case 3:
        xr = 0;
        break;
    }
    if (xr == x)
        cout << a << endl;
    else if ((xr ^ x) == a)
    {
        cout << a + 2 << endl;
    }
    else
        cout << a + 1 << endl;
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