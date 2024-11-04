#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
bool vis[5009];
void marwan()
{
    memset(vis, false, sizeof(vis));
    ll n, ans = INT_MIN;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> m;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;
        ans = max(ans, m[v[i]]);
    }
    // sort(v.begin(), v.end());
    // // cout << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     ll last = v[n - i - 1];
    //     for (auto &vl : m)
    //     {
    //         if (vl.first < last)
    //         {
    //             vl.second -= m[last];
    //             if (vl.second <= 0)
    //             {
    //                 vl.second = 0;
    //             }
    //         }
    //     }
    // }
    // ll count = 0;
    // for (auto vl : m)
    //     if (vl.second)
    //         count += vl.second;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}