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
    vector<ll> v(n), ans;
    for (auto &vl : v)
        cin >> vl;
    ll mx = *max_element(all(v));
    for (ll i = 0; i < n; i++)
    {
        if (v[i] != mx)
        {
            ans.push_back(mx - v[i]);
        }
    }
    sort(all(ans));
    ll x = ans[0];
    for (auto vl : ans)
        x = __gcd(x, vl);
    ll y = 0;
    for (auto vl : ans)
    {
        y += (vl / x);
    }
    cout << y << " " << x << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}