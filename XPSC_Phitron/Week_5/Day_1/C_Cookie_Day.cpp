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
    ll mn = LONG_LONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x >= k)
        {
            mn = min(x % k, mn);
        }
    }
    if (mn == LONG_LONG_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << mn << endl;
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