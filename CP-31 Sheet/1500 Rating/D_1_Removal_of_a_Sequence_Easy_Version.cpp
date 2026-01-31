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
    int a, b, k;
    cin >> a >> b >> k;
    int x = 1e12;
    for (int i = 0; i < a; i++)
    {
        x = (x - (x / b));
    }
    if (x < k)
    {
        minus;
        return;
    }
    // cerr << a << " " << x << endl;
    int l = 1, r = 1e12, ans = x;
    auto ok = [&](int m)
    {
        int val = m;
        for (int i = 0; i < a; i++)
        {
            val = (val - (val / b));
        }
        return val >= k;
    };
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (ok(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
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