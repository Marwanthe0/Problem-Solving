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
    ll x = k;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v), greater<ll>());
    ll ans = v[0];
    for (ll i = 1; i < n; i++)
    {
        v[i] += k;
        ans = max(ans, v[i]);
        k += x;
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