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
    vector<ll> v(n), cp;
    for (auto &vl : v)
        cin >> vl;
    cp = v;
    for (ll i = 1; i < n; i++)
    {
        v[i] = v[i] - v[0];
    }
    n--;
    v.erase(v.begin());
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            m[__gcd(v[i], v[j])]++;
        }
    }
    if (m.empty())
    {
        cout << 1000000000000000000 << endl;
        return;
    }
    for (auto vl : m)
    {
        set<ll> st;
        for (ll i = 0; i < cp.size(); i++)
        {
            st.insert(cp[i] % vl.first);
        }
        if (st.size() == 2)
        {
            cout << vl.first << endl;
            return;
        }
        // cout << st.size() << " ";
        // cerr << vl.first << " ";
    }
    // cout << endl;
    // cerr << endl;
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