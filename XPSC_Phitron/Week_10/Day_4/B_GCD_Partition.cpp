#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
    ll sum = accumulate(all(v), 0ll), x = 0, ans = 0;
    for (ll i = 0; i < n; i++)
    {
        x += (ll)v[i];
        if (x > 0 && (sum - x) > 0)
            ans = max(ans, __gcd(x, sum - x));
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