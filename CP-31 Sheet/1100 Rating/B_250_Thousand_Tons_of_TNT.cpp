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
    int n;
    cin >> n;
    vector<int> v(n), pf(n + 1, 0);
    for (auto &vl : v)
        cin >> vl;
    for (int i = 1; i <= n; i++)
    {
        pf[i] = pf[i - 1] + v[i - 1];
    }
    vector<int> dv = {1};
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
                dv.push_back(n / i);
            dv.push_back(i);
        }
    }
    sort(all(dv));
    int ans = 0;
    for (auto vl : dv)
    {
        int mn = 1e18, mx = -1e18, rem = vl, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            rem--;
            if (rem <= 0)
            {
                mn = min(mn, sum);
                mx = max(mx, sum);
                rem = vl;
                sum = 0;
            }
        }
        // cout << mx << " " << mn << endl;
        // cout << endl;
        ans = max(ans, mx - mn);
    }
    cout << ans << endl;
    // cerr << endl;
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