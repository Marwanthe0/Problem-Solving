#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
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
    vector<ll> temp(v);
    sort(all(temp), greater<ll>());
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        m[temp[i]] = i + 1;
    }
    ll count = 0;
    for (ll i = 0; i < n; i++)
    {
        v[i] = m[v[i]];
        if (i && abs(v[i] - v[i - 1]) == 1)
            count++;
    }
    cout << n - count << endl;
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