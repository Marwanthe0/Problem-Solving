#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll mn = LONG_LONG_MAX;
ll ans(vector<ll> &v, ll sum1, ll sum2, ll idx)
{
    if (idx >= v.size())
        return abs(sum1 - sum2);
    return min(ans(v, sum1 + v[idx], sum2, idx + 1), ans(v, sum1, sum2 + v[idx], idx + 1));
}
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    cout << ans(v, 0, 0, 0) << endl;
    // cout << mn << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}