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
    vector<ll> v(k), ans(n);
    for (auto &vl : v)
        cin >> vl;
    ll dif = LONG_LONG_MAX;
    for (ll i = k - 1; i > 0; i--)
    {
        if (v[i] - v[i - 1] > dif)
        {
            no;
            return;
        }
        else
            dif = v[i] - v[i - 1];
    }
    ll shesh = v[0];
    for (ll i = n - k - 1; i >= 0; i--)
    {
        shesh = shesh - dif;
    }
    if (shesh > dif)
    {
        no;
        return;
    }
    yes;
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