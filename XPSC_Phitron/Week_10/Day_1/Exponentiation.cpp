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
ll ans(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        return ((ans(a, b / 2) % M) * (ans(a, b / 2) % M)) % M;
    }
    else
        return (((a) % M) * ((ans(a, b - 1)) % M) % M);
}
void marwan()
{
    ll a, b;
    cin >> a >> b;
    cout << ans(a, b) << endl;
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