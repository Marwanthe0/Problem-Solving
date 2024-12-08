#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
ll ans(ll n)
{
    if (n == 1)
        return 1;
    else if (n <= 4)
        return 2;
    else
    {
        ll x = 5, y = 10, as = 3;
        while (1)
        {
            if (n >= x && n <= y)
                return as;
            x = ++y;
            y *= 2;
            as++;
        }
    }
}
void marwan()
{
    ll n;
    cin >> n;
    cout << ans(n) << endl;
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