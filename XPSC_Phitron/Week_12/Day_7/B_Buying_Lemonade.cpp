#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (ll i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    ll mn = v[0];
    ll count = mn * n;
    if (k <= count)
    {
        cout << k << endl;
        return;
    }
    for (ll i = 1; i < n; i++)
    {
        if (k <= count)
        {
            cout << i - 1 + k << endl;
            return;
        }
        mn = v[i];
        count += (mn * (n - (i)));
    }
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