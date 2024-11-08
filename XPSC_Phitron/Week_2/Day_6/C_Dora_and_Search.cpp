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
    vector<ll> v(n);
    for (auto &vl : v)
        cin >> vl;
    ll mx = n, mn = 1;
    ll a = 0, b = n - 1;
    // vis[mn] = true, vis[mx] = true;
    pair<ll, ll> ans = {-1, -1};
    while (a < b)
    {
        if (v[a] == mn || v[a] == mx)
        {
            // cout << a << " a =  " << v[a] << endl;
            if (v[a] == mn)
                mn++;
            else
                mx--;
            a++;
            // ll i = a;
            // while (vis[i + 1])
            // {
            //     i++;
            // }
        }
        else if (v[b] == mn || v[b] == mx)
        {
            // cout << b << " b =  " << v[b] << endl;
            if (v[b] == mn)
                mn++;
            else
                mx--;
            b--;
            // ll i = b;
            // while (vis[i])
            // {
            //     i++;
            // }
        }
        else
        {
            ans = {a + 1, b + 1};
            break;
        }
    }

    if (ans.first != -1 && ans.second != -1)
        cout << ans.first << " " << ans.second << endl;
    else
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