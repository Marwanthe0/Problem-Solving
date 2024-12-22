#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll ans(vector<ll> &v)
{
    ll o = 0, z = 0, a = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
            o++;
        if (!v[i])
        {
            a += o;
        }
    }
    return a;
}
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (v == vector<ll>(n, 0) || v == vector<ll>(n, 1))
    {
        cout << n - 1 << endl;
        return;
    }
    vector<ll> w = v, x = v;
    for (ll i = n - 1; i >= 0; i--)
        if (w[i] == 1)
        {
            w[i] = 0;
            break;
        }
    for (ll i = 0; i < n; i++)
    {
        if (!v[i])
        {
            v[i] = 1;
            break;
        }
    }
    cout << max({ans(v), ans(w), ans(x)}) << endl;
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