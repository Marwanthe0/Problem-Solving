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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    map<ll, ll> mp, xp;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
    {
        cin >> vl;
        mp[vl]++;
    }
    ll l = 0, r = 0, count = 0, ans = 0;
    while (r < n)
    {
        xp[a[r]]++;
        if (mp[a[r]] >= xp[a[r]])
            count++;
        if (r - l + 1 == m)
        {
            if (count >= k)
                ans++;
            // cerr << r << " " << l << " " << count << endl;
            xp[a[l]]--;
            if (xp[a[l]] < mp[a[l]])
            {
                count = max((ll)count - 1, 0ll);
            }
            l++;
        }
        r++;
    }
    // cerr << endl;
    cout << ans << endl;
}
main()
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