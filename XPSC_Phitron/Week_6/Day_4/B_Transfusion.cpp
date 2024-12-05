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
    ll sum = accumulate(v.begin(), v.end(), 0);
    ll sum1 = 0, sum2 = 0, x = 0, y = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum1 += v[i];
            x++;
        }
        else
        {
            sum2 += v[i];
            y++;
        }
    }
    cerr << sum1 << " " << x << "::" << sum2 << " " << y << endl;
    if ((sum1 % x == 0 && sum2 % y == 0) && (sum1 / x) + (sum1 % x) == (sum2 / y) + (sum2 % y))
        yes;
    else
        no;
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