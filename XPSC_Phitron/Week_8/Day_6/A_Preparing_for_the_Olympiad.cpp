#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n), b(n);
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        ans += max(0ll, (v[i] - b[i + 1]));
    }
    ans += v[n - 1];
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