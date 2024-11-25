#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += min(v[i] * a, b);
    }
    cout << sum << endl;
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