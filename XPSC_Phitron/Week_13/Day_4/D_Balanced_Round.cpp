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
void marwan()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(all(v));
    vector<ll> dif;
    // for (auto vl : v)
    //     cout << vl << " ";
    // cout << endl;
    // cout << " ";
    ll ans = 0, count = 1;
    for (ll i = 1; i < n; i++)
    {
        dif.push_back(v[i] - v[i - 1]);
        // cout << dif.back() << " ";
        if (dif.back() <= k)
        {
            count++;
            ans = max(count, ans);
        }
        else
            count = 1;
    }
    // cout << endl;
    cout << min(n - 1, n - ans) << endl;
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