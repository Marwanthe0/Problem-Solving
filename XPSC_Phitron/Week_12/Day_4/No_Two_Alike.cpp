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
    map<ll, ll> lsi, paici;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        lsi[v[i]] = i;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll last = lsi[v[i]];
        set<ll> s;
        while (i < last)
        {
            last = max((ll)last, (ll)lsi[v[i]]);
            s.insert(v[i]);
            i++;
        }
        ans += s.size();
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