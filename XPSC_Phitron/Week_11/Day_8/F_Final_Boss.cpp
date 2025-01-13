#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll h, n;
    cin >> h >> n;
    vector<ll> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    ll sum = accumulate(all(a), 0);
    if (h <= sum)
    {
        cout << 1 << endl;
        return;
    }
    ll l = 1, r = 1e18, mid, ans;
    auto ok = [&](ll mid)
    {
        ll count = sum;
        for (ll i = 0; i < n; i++)
        {
            count += ((mid - 1) / b[i]) * a[i];
            if (count >= h)
                return true;
        }
        return count >= h;
    };
    while (l <= r)
    {
        mid = l + (r - l) / 2;
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}