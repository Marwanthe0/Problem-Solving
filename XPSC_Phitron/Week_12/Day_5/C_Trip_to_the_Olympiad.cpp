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
void prllbn(ll n)
{
    ll x = __lg(n);
    for (ll i = x; i >= 0; i--)
        cout << ((n & (1 << i)) != 0) << " ";
    cout << endl;
}
void marwan()
{
    ll l, r;
    cin >> l >> r;
    ll x = 63 - __builtin_clzll(l ^ r);
    ll a = ((l & r));
    for (int i = x - 1; i >= 0; i--)
        a = ((ll)a & ~(1ll << (ll)x));
    a |= 1 << x;
    // prllbn(a);
    // prllbn(r);
    // a++;
    ll b = a - 1, c;
    if (b > l)
        c = b - 1;
    else
        c = a + 1;
    cout << a << " " << b << " " << c << endl;
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