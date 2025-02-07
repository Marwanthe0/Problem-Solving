#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define a(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k;
    cin >> n >> k;
    int l = 1, r = (2 * n * (1.0)) - 1ll, ans, xx = 2 * n * (1.0) - 1ll;
    auto ok = [&](int mid)
    {
        int x = ((mid * (1.0) * (mid + 1)) / 2ll);
        if (mid > n)
        {
            x = (n * (1.0) * (n + 1)) / 2ll;
            int yy = xx - mid;
            int y = ((n * (1.0) * (n - 1)) / 2ll) - ((yy * (1.0) * (yy + 1)) / 2ll);
            x += y;
        }
        return x >= k;
    };
    while (l <= r)
    {
        int mid = l * (1.0) + (r * (1.0) - l * (1.0)) / 2ll;
        if (ok(mid))
        {
            ans = mid, r = mid - 1ll;
        }
        else
            l = mid + 1ll;
    }
    if (l > xx)
        cout << r << endl;
    else
        cout << l << endl;
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