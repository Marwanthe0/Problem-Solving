#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cerr << "YES" << endl
#define no cerr << "NO" << endl
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second > b.second;
}
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v[n + 1];
    vector<pair<ll, ll>> ed(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++)
    {
        ed[i] = {i, v[i].size()};
    }
    sort(all(ed), cmp);
    vector<ll> shesh;
    for (ll i = 0; i < 2; i++)
    {
        cout << ed[i].first << endl;
        ll x = ed[i].first;
        for (auto vl : v[x])
        {
            auto it = lower_bound(all(v[vl]), x);
            v[vl].erase(it);
        }
        sort(all(ed), cmp);
        v[x].clear();
    }
    ll ans = n - 2;
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (auto &vl : v[i])
    //     {
    //         if (vl == shesh[0] || vl == shesh[1])
    //             ;
    //         else
    //         {
    //             ans--;
    //             auto it = lower_bound(all(v[vl]), i);
    //             v[vl].erase(it);
    //         }
    //     }
    //     cerr << endl;
    // }
    cerr << endl;
    // cout << ans << endl;
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