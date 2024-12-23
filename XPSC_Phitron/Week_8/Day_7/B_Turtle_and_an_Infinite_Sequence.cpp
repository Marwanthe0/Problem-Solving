#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, m;
    cin >> n >> m;
    if (!m)
    {
        cout << n << endl;
        return;
    }
    ll a = max(0ll, n - m), b = n + m;
    ll x = __lg(a ^ b);
    for (ll i = x; i >= 0; i--)
    {
        a = a | (1 << i);
    }
    cout << a << endl;
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