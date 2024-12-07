#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define N 1000000
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1, 0), pf(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    ll mx = LONG_LONG_MIN, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v[i];
        mx = max(mx, v[i]);
        if (pf[i] - mx == mx)
            ans++;
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