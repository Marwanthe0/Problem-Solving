#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i < n - 1; i++)
    {
        if (((2 * (min(v[i], v[i - 1])) > max(v[i], v[i - 1]))) || ((2 * (min(v[i], v[i + 1])) > max(v[i], v[i + 1]))))
        {
            yes;
            return;
        }
    }
    if ((2 * (min(v[0], v[1])) > max(v[0], v[1])) || ((2 * min(v[n - 1], v[n - 2])) > max(v[n - 1], v[n - 2])))
    {
        yes;
        return;
    }
    no;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}