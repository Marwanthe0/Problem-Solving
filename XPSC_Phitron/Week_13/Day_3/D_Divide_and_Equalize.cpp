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
    vector<ll> v(n);
    map<ll, ll> m;
    for (auto &vl : v)
    {
        cin >> vl;
        for (ll i = 2; i * i <= vl; i++)
        {
            while (vl % i == 0)
            {
                m[i]++;
                vl /= i;
            }
        }
        if (vl > 1)
            m[vl]++;
    }
    for (auto [x, y] : m)
    {
        if (y % n)
        {
            no;
            return;
        }
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