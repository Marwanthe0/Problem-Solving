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
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll l = 1, r = 1e18, mid, count, ans;
    auto ok = [&](ll mid)
    {
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            cnt += (mid / v[i]);
            if (cnt >= k)
                return true;
        }
        return cnt >= k;
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
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}