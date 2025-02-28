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
    int a = n / x, b = n / y, c = n / ((x * y) / __gcd(x, y));
    // cout << a << " " << b << " " << c << endl;
    a -= c, b -= c;
    a = ((n * (n + 1)) / 2) - (((n - a) * (n - a + 1)) / 2);
    cout << a - (b * (b + 1) / 2) << endl;
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