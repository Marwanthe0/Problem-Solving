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
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v), greater<int>());
    for (int i = 1; i < n; i += 2)
    {
        ll mx = v[i - 1];
        if (k <= 0)
            break;
        ll dif = min(k, mx - v[i]);
        k -= dif;
        v[i] += dif;
    }
    // for (auto vl : v)
    //     cout << vl << " ";
    // cout << endl;
    ll x = 0,
       y = 0;
    sort(all(v), greater<ll>());
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            x += v[i];
        }
        else
            y += v[i];
    }
    cout << x - y << endl;
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