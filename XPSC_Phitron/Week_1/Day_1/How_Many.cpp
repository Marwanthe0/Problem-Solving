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
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(v.begin(), v.end());
    ll ans = 0;
    for (auto vl : v)
        ans += vl;
    if (ans % 2)
    {
        ll x;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] % 2)
            {
                x = v[i];
                break;
            }
        }
        cout << ans - x << endl;
    }
    else
        cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}