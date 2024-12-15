#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll ans = 0;
    ans += min(a, n);
    ans += min(b, n);
    n = (2 * n) - (min(n, a) + min(n, b));
    if (n >= 0)
        ans += min(n, c);
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