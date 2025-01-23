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
    map<ll, ll> m, ans;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x <= n)
            m[x]++;
    }
    for (auto [x, y] : m)
    {
        for (ll i = x; i <= n; i += x)
        {
            ans[i] += y;
        }
    }
    ll last = 0;
    for (auto vl : ans)
        last = max(last, (ll)vl.second);
    cout << last << endl;
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