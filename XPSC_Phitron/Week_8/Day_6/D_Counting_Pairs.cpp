#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(v.begin(), v.end());
    ll sum = accumulate(v.begin(), v.end(), 0);
    ll ans = 0;
    for (auto vl : v)
        cerr << vl << " ";
    cerr << endl;
    for (ll i = 0; i < n; i++)
    {
        ll lower = sum - y - v[i];
        ll upper = sum - x - v[i];

        int l = lower_bound(v.begin() + i + 1, v.end(), lower) - v.begin();
        int u = upper_bound(v.begin() + i + 1, v.end(), upper) - v.begin();

        ans += (u - l);
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