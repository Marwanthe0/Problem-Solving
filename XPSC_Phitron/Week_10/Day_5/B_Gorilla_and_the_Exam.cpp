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
bool cmp(pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; }
void marwan()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    vector<ll> v(n);
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    vector<int> st;
    for (auto vl : m)
        st.push_back(vl.second);
    sort(all(st));
    int x = 0;
    for (int i = 0; i < st.size(); i++)
    {
        if (k == 0)
        {
            cout << max((ll)st.size() - i, 1ll) << endl;
            return;
        }
        else if (k < 0)
        {
            cout << max((ll)st.size() - i + 1, 1ll) << endl;
            return;
        }
        k -= st[i];
    }
    cout << 1 << endl;
    // cout << max((ll)(m.size() - k), 1ll) << endl;
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