#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan()
{
    int n, k, ans = 0ll;
    cin >> n >> k;
    vector<int> v(n), pf(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (k < pf[i])
            break;
        ans += (((k - pf[i]) + 1) / i) + (((k - pf[i]) + 1) % i != 0);
    }
    cout << ans << endl;
}
int32_t main()
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