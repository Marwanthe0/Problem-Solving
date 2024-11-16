#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, mx = LONG_MAX;
    cin >> n;
    ll sum = 0;
    vector<ll> v(n);
    ll cnt = 0, z = 0;
    for (auto &vl : v)
    {
        cin >> vl;
        if (vl == 0)
            z++;
        if (vl < 0)
        {
            cnt++;
        }
        mx = min(abs(vl), mx);
        sum += abs(vl);
    }
    if (cnt % 2 == 0 || z > 0)
    {
        cout << sum << endl;
    }
    else
        cout << sum - (2 * mx) << endl;
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