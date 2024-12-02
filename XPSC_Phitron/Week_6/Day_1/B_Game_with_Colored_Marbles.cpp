#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; }
void marwan()
{
    ll n;
    cin >> n;
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        m[x]++;
    }
    auto customComparator = [](const pair<ll, ll> &a, const pair<ll, ll> &b)
    { return a.first < b.first; };

    multiset<pair<ll, ll>, decltype(customComparator)> s(
        customComparator);

    for (auto vl : m)
    {
        s.insert({vl.second, vl.first});
    }
    map<ll, ll> xs;
    ll cnt = 1, ans = 0;
    while (!s.empty())
    {
        if (cnt % 2)
        {
            xs[s.begin()->second]++;
            ll x = s.begin()->first, y = s.begin()->second;
            x--;
            s.erase(s.begin());
            if (x > 0)
                s.insert({x, y});
        }
        else
        {
            ll x = s.begin()->first, y = s.begin()->second;
            x--;
            s.erase(s.begin());
            if (x > 0)
                s.insert({x, y});
        }
        cnt++;
    }
    for (auto vl : xs)
    {
        if (vl.second == m[vl.first])
            ans++;
    }
    cout << xs.size() + ans << endl;
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