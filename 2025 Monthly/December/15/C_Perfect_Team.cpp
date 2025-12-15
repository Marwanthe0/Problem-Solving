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
    int c, m, n;
    cin >> c >> m >> n;
    int ans = min({c, m, n});
    c -= ans, m -= ans;
    if (c == 0 || m == 0)
    {
        cout << ans << endl;
        return;
    }
    int x = max(c, m), y = min(c, m);
    if (x >= 2 * y)
        ans += y;
    else
    {
        ans += (x + y) / 3;
    }
    cout << ans << endl;
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