#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll x, y;
    cin >> x >> y;
    ll ans = (y / 2) + (y % 2 != 0);
    x -= (((y / 2) * 7) + (y % 2) * (11));
    if (x > 0)
    {
        ans += (x / 15) + (x % 15 != 0);
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