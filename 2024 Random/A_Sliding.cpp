#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, m, x, y, ans;
    cin >> n >> m >> x >> y;
    ll a = (m - y) + ((n - x) * m);
    if (n - x)
    {
        ans = (a - (n - x)) + (m) * (n - x);
    }
    else
        ans = a;
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}