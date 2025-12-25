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
    map<int, int> m;
    vector<int> v(n);
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    int ans = 0, mx = 0, last = -1;
    for (auto [x, y] : m)
    {
        // cerr << x << " " << y << endl;
        if (last == -1)
        {
            last = x;
        }
        else
        {
            if (x - last > 1)
            {
                ans += mx;
                mx = 0;
            }
            else if (y < mx)
            {
                ans += mx - y;
                mx = y;
            }
        }
        mx = max(mx, y);
        last = x;
    }
    ans += mx;
    // cerr << endl;
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