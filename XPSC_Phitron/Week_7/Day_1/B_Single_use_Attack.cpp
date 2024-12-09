#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll h, x, y;
    cin >> h >> x >> y;
    ll a = (h / x) + (h % x != 0);
    h -= y;
    ll b = (h / x) + (h % x != 0);
    cout << min(a, b + 1) << endl;
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