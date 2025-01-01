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
    ll x = v[0];
    sort(all(v));
    if (x == v[n - 1])
    {
        cout << (1e6 - (x - (((x - v[n - 2] - 1) / 2) + ((x - v[n - 2] - 1) % 2)))) + 1 << endl;
    }
    else if (x == v[0])
    {
        cout << x + (((v[1] - x - 1) / 2) + (v[1] - x - 1) % 2) << endl;
    }
    else
    {
        ll it = lower_bound(all(v), x) - v.begin();
        int prev = v[it - 1], next = v[it + 1];
        // cout << v[it] << " " << prev << " " << next << endl;
        ll ans = (x - prev - 1) / 2 + ((x - prev - 1) % 2) + ((next - x - 1) / 2) + ((next - x - 1) % 2) + 1;
        cout << ans << endl;
        // ll ans = (((x - v[it - 1] - 1) / 2) + ((x - v[it - 1] - 1) % 2)) + (((v[it + 1] - x) / 2) + ((v[it + 1] - x) % 2));
        // cout << ans << endl;
    }
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