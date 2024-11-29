#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    map<ll, ll> m;
    ll ans, oc = LONG_LONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        m[x]++;
        if (m[x] > oc)
        {
            oc = m[x];
            ans = x;
        }
    }
    ll count = 0;
    while (oc < n)
    {
        count++;
        count += min(oc, n - oc);
        oc *= 2;
    }
    cout << count << endl;
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