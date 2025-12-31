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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(all(v));
    map<int, int> mp;
    for (auto [x, y] : v)
    {
        if (x < y)
            swap(x, y);
        mp[x] = max(y, mp[x]);
    }
    int ans = 0ll, mx = 1ll;
    for (int i = 1; i <= n; i++)
    {
        if (mp.find(i) != mp.end())
        {
            ans += min((i - mx) + 1ll, i - mp[i]), mx = max(mp[i] + 1ll, mx);
        }
        else
        {
            int t = (i - mx) + 1ll;
            ans += t;
        }
        // cerr << i << " " << ans << endl;
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