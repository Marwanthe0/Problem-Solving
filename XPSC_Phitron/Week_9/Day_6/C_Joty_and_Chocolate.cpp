#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, a, b, p, q, ans = 0, x = 0, y = 0, z = 0;
    cin >> n >> a >> b >> p >> q;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i % a == 0 && i % b == 0)
    //     {
    //         ans += max(p, q);
    //     }
    //     else if (i % a == 0)
    //         ans += p;
    //     else if (i % b == 0)
    //         ans += q;
    // }
    for (ll i = a; i <= n; i += a)
    {
        x++;
    }
    for (ll i = b; i <= n; i += b)
        y++;
    ll lcm = (a * b) / (__gcd(a, b));
    for (ll i = lcm; i <= n; i += lcm)
        z++;
    cerr << x << " " << y << " " << z << endl;
    x -= z, y -= z;
    ans += (p * x) + (q * y) + (z * max(p, q));
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}