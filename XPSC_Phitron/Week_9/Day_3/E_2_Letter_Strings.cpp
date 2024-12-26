#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
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
    unordered_map<string, ll> m;
    vector<string> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        for (auto vl : m)
        {
            if ((vl.first[0] != v[i][0] && vl.first[1] != v[i][1]) || (vl.first[0] == v[i][0] && vl.first[1] == v[i][1]))
                continue;
            if (v[i][0] == vl.first[0] || v[i][1] == vl.first[1] || v[i][0] == vl.first[1] || v[i][1] == vl.first[0])
            {
                ans += vl.second;
            }
        }
        m[v[i]]++;
    }
    cout << ans << endl;
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