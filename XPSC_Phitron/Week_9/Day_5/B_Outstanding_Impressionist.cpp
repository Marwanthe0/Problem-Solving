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
ll findLowestInRange(set<ll> &s, ll l, ll r)
{
    auto it = s.lower_bound(l);
    if (it != s.end() && *it <= r)
    {
        return *it; // Return the found element
    }

    return -1;
}
void marwan()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    map<ll, ll> m;
    ll mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    for (auto &[x, y] : v)
    {
        cin >> x >> y;
        mn = min(x, mn), mx = max(y, mx);
        if (x == y)
            m[x]++;
    }
    set<ll> st;
    for (ll i = mn; i <= mx; i++)
    {
        if (m[i] == 0)
            st.insert(i);
    }
    // for (auto vl : m)
    //     cout << vl.first << " ";
    // cout << endl;
    vector<ll> ans(n, -1);
    for (ll i = 0; i < n; i++)
    {
        if (v[i].first == v[i].second)
        {
            if (m[v[i].first] == 1)
            {
                ans[i] = 1;
            }
        }
        else
        {
            ll xss = findLowestInRange(st, v[i].first, v[i].second);
            if (xss != -1)
            {
                ans[i] = xss;
                m[xss]++;
                // st.erase(xss);
            }
        }
    }
    // cerr << endl;
    for (auto vl : ans)
    {
        if (vl == -1)
            cout << '0';
        else
            cout << '1';
        // cout << vl << " ";
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