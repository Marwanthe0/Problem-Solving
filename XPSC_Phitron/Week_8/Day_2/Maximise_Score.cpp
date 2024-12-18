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
    vector<ll> v(n), d(n);
    for (auto &vl : v)
        cin >> vl;
    for (ll i = 0; i < n; i++)
    {
        if (!i)
            d[i] = abs(v[i] - v[i + 1]);
        else if (i == n - 1)
        {
            d[i] = abs(v[i] - v[i - 1]);
        }
        else
            d[i] = max(abs(v[i] - v[i + 1]), abs(v[i] - v[i - 1]));
    }
    cout << *min_element(d.begin(), d.end()) << endl;
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