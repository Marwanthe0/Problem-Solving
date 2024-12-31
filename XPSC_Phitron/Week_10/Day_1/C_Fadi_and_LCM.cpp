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
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
void marwan()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v, ans;
    for (ll i = 1; (i * i) <= n; i++)
    {
        if (n % i == 0)
            v.push_back({i, (n / i)});
    }
    for (ll i = 0; i < v.size(); i++)
    {
        if (lcm(v[i].first, v[i].second) == n)
            ans.push_back(v[i]);
    }
    ll x, y = LONG_LONG_MAX;
    for (auto vl : ans)
    {
        if (vl.second < y)
        {
            x = vl.first, y = vl.second;
        }
        // cout << vl.first << " " << vl.second << endl;
    }
    cout << x << " " << y << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}