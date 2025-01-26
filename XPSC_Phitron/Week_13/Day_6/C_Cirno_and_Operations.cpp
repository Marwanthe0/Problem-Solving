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
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll ans = accumulate(all(v), 0ll);
    while (v.size() != 1)
    {
        vector<ll> a, b;
        for (ll i = 1; i < n; i++)
        {
            a.push_back(v[i] - v[i - 1]);
        }
        for (ll j = n - 2; j >= 0; j--)
        {
            b.push_back(v[j] - v[j + 1]);
        }
        ll x = accumulate(all(a), 0ll), y = accumulate(all(b), 0ll);
        if (x > y)
        {
            v = a;
            ans = max(ans, x);
            n = v.size();
        }
        else
        {
            v = b;
            ans = max(ans, y);
            n = v.size();
        }
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