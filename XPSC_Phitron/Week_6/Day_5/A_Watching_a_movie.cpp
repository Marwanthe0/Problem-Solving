#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    for (auto &vl : v)
        cin >> vl.first >> vl.second;
    ll start = 1, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll x = v[i].first, y = v[i].second;
        if (start + k <= x)
        {
            start += ((x - start) / k) * k;
        }
        ans += (y - start) + 1;
        start += (y - start) + 1;
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}