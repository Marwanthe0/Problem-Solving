#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n, m;
    cin >> n >> m;
    if (!m)
    {
        cout << n << endl;
        return;
    }
    m = n + m;
    // ll x = __lg(n ^ m);
    // for (ll i = x; i >= 0; i--)
    // {
    //     n = n | (1 << i);
    // }
    // cout << n << endl;
    m = (m | (m - 1)) | (m + 1);
    cout << m << endl;
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