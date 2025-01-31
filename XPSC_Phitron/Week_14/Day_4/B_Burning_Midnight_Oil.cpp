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
    int n, k;
    cin >> n >> k;
    int l = 1, r = 1e12, mid, ans;
    auto ok = [&](int mid)
    {
        int sum = 0;
        while (mid > 0)
        {
            sum += mid;
            mid /= k;
        }
        return sum >= n;
    };
    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        if (ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}