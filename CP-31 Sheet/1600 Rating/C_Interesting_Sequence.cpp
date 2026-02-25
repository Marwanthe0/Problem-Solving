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
    int n, m, x;
    cin >> n >> m;
    if (m > n)
    {
        minus;
        return;
    }
    x = n;
    // for (int i = __lg(n); i >= 0ll; i--)
    // {
    //     if ((n >> i) & 1)
    //         cerr << 1;
    //     else
    //         cerr << 0;
    // }
    // cerr << "            ";
    // for (int i = __lg(m); i >= 0ll; i--)
    // {
    //     if ((m >> i) & 1)
    //         cerr << 1;
    //     else
    //         cerr << 0;
    // }
    bool flag = false, flag2 = true;
    for (int i = __lg(n); i >= 0ll; i--)
    {
        if (flag && (1ll & (m >> i)))
        {
            minus;
            return;
        }
        if ((1ll & (n >> i)) != (1ll & (m >> i)))
        {
            if (!flag)
            {
                x = x & ((~1ll) << i);
                x = (x | (1ll << (i + 1ll)));
            }
            flag = true;
        }
    }
    if (x >= n)
        cout << x << endl;
    else
        minus;
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