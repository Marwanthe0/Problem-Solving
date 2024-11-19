#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second > b.second;
}
void marwan()
{
    ll n;
    cin >> n;
    ll x = (n * (n - 1)) / 2;
    vector<ll> v;
    map<ll, ll> m;
    for (ll i = 0; i < x; i++)
    {
        ll x;
        cin >> x;
        m[x]++;
    }
    ll oc = n - 1;
    for (auto vl : m)
    {
        while (vl.second > 0)
        {
            vl.second -= oc;
            oc--;
            v.push_back(vl.first);
        }
    }
    v.push_back(m.rbegin()->first);
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