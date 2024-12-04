#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool cmp(pair<ll, ll> a, pair<ll, ll> b) { return a.first * a.second > b.first * b.second; }
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v(n);
    for (auto &vl : v)
        cin >> vl.first;
    for (auto &vl : v)
        cin >> vl.second;

    sort(v.begin(), v.end(), cmp);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += v[i].first * v[i].second;
        if (sum >= k)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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