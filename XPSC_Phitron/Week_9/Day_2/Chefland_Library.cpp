#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    map<ll, ll> m;
    for (ll i = 1; i <= n; i++)
    {
        m[v[i - 1]] = max(m[v[i - 1]], i);
    }
    ll ans = 0;
    for (auto vl : m)
        ans += vl.second;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}