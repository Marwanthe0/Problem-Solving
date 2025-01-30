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
bool ok(int &mid, int &n)
{
    return mid * 1.0 * (mid - 1) / 2.0 <= n;
}
void marwan()
{
    int n;
    cin >> n;
    int l = 1, r = 1e18, mid, ans;
    while (l <= r)
    {
        mid = (int)(l + ((r - l) / 2));
        if (ok(mid, n))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
        // cerr << l << ":" << r << " ";
    }
    if (ans * (ans - 1) / 2 == n)
    {
        cout << ans << endl;
    }
    else
        cout << ans + (n - (ans * (ans - 1) / 2)) << endl;
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