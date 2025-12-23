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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), a(k + 1);
    for (int i = 1; i <= k; i++)
        a[i] = -1;
    map<int, multiset<int>> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]].insert(i - a[v[i]] - 1);
        a[v[i]] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        m[i].insert(n - a[i] - 1);
    }
    int ans = INT_MAX;
    for (auto [x, y] : m)
    {
        // cout << x << endl;
        int last = *(--y.end());
        y.erase((--y.end()));
        y.insert(last / 2);
        ans = min(ans, *(--y.end()));
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