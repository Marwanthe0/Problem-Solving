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
    vector<pair<int, int>> v(n);
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        mx = max(mx, v[i].second);
    }
    int l = v[0].first, r = mx;
    auto ok = [&](int m)
    {
        int nl = 0, nr = 0;
        for (auto [x, y] : v)
        {
            nl = max(x, nl - m), nr = min(y, nr + m);
            if (nl > nr)
                return false;
        }
        return true;
    };
    int ans = mx;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        bool ck = ok(m);
        // cerr << m << " " << ck << endl;
        if (ck)
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
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