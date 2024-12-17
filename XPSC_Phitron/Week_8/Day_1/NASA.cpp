#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mx = (1 << 15);
vector<ll> p;
bool pal(ll n)
{
    string s = to_string(n);
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
void pre()
{
    for (ll i = 0; i < mx; i++)
    {
        if (pal(i))
        {
            p.push_back(i);
        }
    }
}
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n),oc(mx,0);
    for (auto &vl : v)
    {
        cin >> vl;
        oc[vl]++;
    }
    ll count = n;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < p.size(); j++)
        {
            count += oc[v[i] ^ p[j]];
        }
    }
    cout << count / 2 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    // for (auto vl : p)
    //     cout << vl << ' ';
    ll t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}