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
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n), pf(n + 1, 0), a(n);
    for (auto &vl : v)
        cin >> vl;
    for (ll i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v[i - 1];
    }
    a[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        if (v[i] >= a[i - 1])
            a[i] = v[i];
        else
            a[i] = a[i - 1];
    }
    for (ll i = 0; i < q; i++)
    {
        ll k;
        cin >> k;
        ll idx = upper_bound(all(a), k) - a.begin() - 1;
        if (idx < 0)
            cout << 0 << " ";
        else
            cout << pf[idx + 1] << " ";
    }
    cout << endl;
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