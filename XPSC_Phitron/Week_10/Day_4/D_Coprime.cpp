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
    vector<ll> v(n + 1);
    map<ll, ll> m;
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
        m[v[i]] = i;
    }
    ll ans = -1;
    for (auto vl : m)
    {
        for (auto cl : m)
        {
            if (__gcd(vl.first, cl.first) == 1)
            {
                ans = max(ans, vl.second + cl.second);
            }
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