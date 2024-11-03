#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<ll, ll> a, pair<ll, ll> b) { return a.second > b.second; }
void marwan()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> m;
    vector<ll> v;
    for (ll i = 0; i < k; i++)
    {
        ll a, b;
        cin >> a >> b;
        m[a] += b;
    }
    // for (auto vl : m)
    //     cout << vl.first << " " << vl.second << endl;
    for (auto vl : m)
        v.push_back(vl.second);
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0, count = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (count >= n)
            break;
        // cout << v[i] << " ";
        ans += v[i];
        count++;
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