#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n), pf(n + 1);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v[i - 1];
    }
    ll l = v[0], r = 1e15, mid, ans;
    auto ok = [&](ll mid)
    {
        ll count = 0;
        // for (auto &vl : v)
        // {
        //     if (vl < mid)
        //         count += (ll)((ll)mid - (ll)vl);
        //     else
        //         break;
        // }
        int x = upper_bound(all(v), mid) - v.begin() - 1;
        x = (x * mid) - pf[x];
        return x <= k;
    };
    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        if (ok(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
        // cout << l << " " << r << endl;
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