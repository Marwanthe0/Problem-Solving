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
    ll x = (n / (a + b + c));
    ll ans = (x * 3);
    if (n % (a + b + c) == 0)
        ;
    else if (n % (a + b + c) <= a)
        ans++;
    else if (n % (a + b + c) <= (a + b))
        ans += 2;
    else
        ans += 3;
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