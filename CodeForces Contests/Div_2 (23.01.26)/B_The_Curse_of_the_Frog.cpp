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
    int n, tg;
    cin >> n >> tg;
    // vector<vector<int>> v(n, vector<int>(m, 0));
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({b * a - c, a * (b - 1ll)});
    }
    int mx = -1e18;
    for (auto [x, y] : v)
    {
        tg -= y;
        if (tg <= 0ll)
        {
            cout << 0ll << endl;
            return;
        }
        // cerr << x << " " << y << endl;
        mx = max(mx, x);
    }
    if (mx <= 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << tg / mx + (tg % mx != 0ll) << endl;
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