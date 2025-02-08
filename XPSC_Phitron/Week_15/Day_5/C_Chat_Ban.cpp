#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define a(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
int get(int x)
{
    return (x * (1ll) * (x + 1)) / 2;
}
void marwan()
{
    int k;
    long long x;
    cin >> k >> x;
    long long l = 1, r = 2 * k - 1;
    long long res = 2 * k - 1;
    bool over = false;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (mid >= k)
        {
            over = (get(k) + get(k - 1) - get(2 * k - 1 - mid) >= x);
        }
        else
        {
            over = (get(mid) >= x);
        }
        if (over)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res << endl;
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