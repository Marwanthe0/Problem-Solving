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
    int n, m, k;
    cin >> n >> m >> k;
    int l = (k / n) + (k % n != 0);
    int low = 1, high = l, ans = l;
    auto ok = [&](int sz)
    {
        int need = sz + 1;
        int blocks = (m / (need)) * sz;
        blocks += (m % need);
        return blocks >= l;
    };
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (ok(mid))
        {
            ans = mid, high = mid - 1;
        }
        else
            low = mid + 1;
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