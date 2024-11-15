#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll n, m, sum = 0, ci, cj;
bool valid(ll i, ll j) { return i >= 0 && i < n && j >= 0 && j < m; }
vector<pair<ll, ll>> path = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
ll sums(ll i, ll j, ll x, ll y, vector<vector<ll>> &a)
{
    ll sum = 0;
    while (i >= 0 && i < n && j >= 0 && j < m)
    {
        sum += a[i][j];
        i += x;
        j += y;
    }
    return sum;
}
void marwan()
{
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            sum = a[i][j];
            for (ll k = 0; k < 4; k++)
            {
                ll x = path[k].first, y = path[k].second;
                sum += sums(i + x, j + y, x, y, a);
            }
            ans = max(ans, sum);
        }
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