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
    ll x, y, k,m,req;
    cin >> x >> y >> k;
    while (k > 0 && x != 1)
    {
        req =  (x / y + 1) * y - x;
        req = max(1ll, req);
        req = min(req, k);
        x += req;
        while ((x % y) == 0)
            x /= y;
        k -= req;
    }
    cout << x+k%(y-1) << endl;
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