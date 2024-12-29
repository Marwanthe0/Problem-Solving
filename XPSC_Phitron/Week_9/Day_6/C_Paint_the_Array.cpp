#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
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
    ll x = v[1], y = v[0];
    for (ll i = 0; i < n; i++)
    {
        if (i & 1)
        {
            x = __gcd(x, v[i]);
        }
        else
            y = __gcd(y, v[i]);
    }
    if (x == y)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        bool flag = true;
        for (ll i = 0; i < n; i += 2)
        {
            if (v[i] % x == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << x << endl;
            return;
        }
        flag = true;
        for (ll i = 1; i < n; i += 2)
        {
            if (v[i] % y == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << y << endl;
            return;
        }
    }
    cout << 0 << endl;
    // cout << x << " " << y << endl;
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