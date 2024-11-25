#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = c - a, y = d - b;
    if (x > y || y < 0)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        cout << y + (y - x) << endl;
    }
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