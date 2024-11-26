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
    vector<ll> v(n), pf(n + 1, 0);
    for (auto &vl : v)
        cin >> vl;
    sort(v.begin(), v.end());
    for (ll i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v[i - 1];
        auto it = upper_bound(v.begin(), v.end(), pf[i]);
        if (it != v.end())
        {
            swap(v[i], v[it - v.begin()]);
        }
        else
            break;
    }
    ll count = 0;
    for (ll i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v[i - 1];
    }
    for (ll i = 0; i < n; i++)
    {
        cerr << pf[i] << " ";
        if (pf[i] >= v[i])
            count++;
    }
    cerr << endl;
    cout << count << endl;
    for (auto vl : v)
        cout << vl << " ";
    cout << endl;
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