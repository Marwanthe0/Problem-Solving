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
    vector<ll> v(n), at;
    map<ll, ll> a, m;
    for (auto &vl : v)
    {
        cin >> vl;
        a[vl]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            at.push_back(i);
        }
    }
    auto it = at.begin();
    for (ll i = 0; i < n; i++)
    {
        m[v[i]]++;
        if (m[v[i]] > 1)
        {
            cout << *(it) << " ";
            it++;
        }
        else
            cout << v[i] << " ";
    }
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