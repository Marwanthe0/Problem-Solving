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
    int n, x, m;
    cin >> n >> x >> m;
    bool flag = false;
    int mn = x, mx = x;
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        if (x >= l && x <= r)
            flag = true;
        if (flag)
        {
            if (l <= mn && r >= mn)
            {
                mn = min(mn, l), mx = max(mx, r);
            }
            else if (l <= mx && r >= mx)
            {
                mn = min(l, mn), mx = max(r, mx);
            }
        }
        // cerr << mn << " " << mx << endl;
    }
    cerr << mx << " " << mn << endl;
    cout << mx - mn + 1 << endl;
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