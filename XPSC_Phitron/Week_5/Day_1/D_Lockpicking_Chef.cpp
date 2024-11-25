#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll round(ll a, ll b)
{
    ll x, y;
    if (a > b)
    {
        x = min(a - b, (10 - a) + b);
    }
    else
    {
        x = min(b - a, (10 - b) + a);
    }
    return x;
}
void marwan()
{
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    string a;
    ll sum = 0, ans = LONG_LONG_MAX;
    for (ll i = 0; i <= n - m; i++)
    {
        ll x = i;
        sum = 0;
        for (ll j = 0; j < m; j++)
        {
            sum += round(s[x] - '0', t[j] - '0');
            x++;
        }
        ans = min(sum, ans);
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