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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int b, g, x, y, n;
    cin >> b >> g >> x >> y >> n;
    if (x + y > n)
    {
        minus;
        return;
    }
    int r = ((b + g) / n) + ((b + g) % n != 0);
    if (r * x > b)
    {
        minus;
        return;
    }
    if (r * y > g)
    {
        minus;
        return;
    }
    int u = min(b / x, g / y);
    if (r > u)
    {
        minus;
        return;
    }
    cout << r << endl;
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