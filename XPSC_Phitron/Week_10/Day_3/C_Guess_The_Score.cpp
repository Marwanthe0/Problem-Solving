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
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (auto &vl : c)
        cin >> vl;
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        ll ti, si;
        cin >> ti >> si;
        // cout << ti << " " << si << endl;
        // if (si > 0)
        if (si > 0)
            sum += max(c[i], a[i] - (b[i] * ti) - (50 * (si - 1)));
    }
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}