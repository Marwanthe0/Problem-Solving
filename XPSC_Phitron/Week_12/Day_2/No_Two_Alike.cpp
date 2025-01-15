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
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    map<ll, pair<ll, ll>> m;
    for (ll i = 1; i <= n; i++)
    {
        if (!m[v[i]].first)
        {
            m[v[i]].first = i;
        }
        else
            m[v[i]].second = i;
    }
    ll sz = m.size();
    if (m.size() == n)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    for (auto vl : m)
    {
        ll x = vl.first, a = vl.second.first, b = vl.second.second;
        cerr << x << " " << a << " " << b << endl;
        set<ll> s;
        if (a == b)
            continue;
        for (ll i = a; i <= b; i++)
        {
            if (v[i] != x)
            {
                b = max(b, m[v[i]].second);
                m.erase(v[i]);
            }
            s.insert(v[i]);
        }
        // cout << s.size() << " ";
        ans += s.size();
    }
    cerr << endl;
    cout << min(sz, ans) << endl;
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