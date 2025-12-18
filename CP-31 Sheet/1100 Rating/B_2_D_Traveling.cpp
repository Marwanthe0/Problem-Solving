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
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    pair<int, int> x = v[a - 1], y = v[b - 1];
    int ans = 1e17, ans2 = 1e17;
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, abs(x.first - v[i].first) + abs(x.second - v[i].second));
        ans2 = min(ans2, abs(y.first - v[i].first) + abs(y.second - v[i].second));
    }
    cout << min(ans + ans2, abs(x.first - y.first) + abs(x.second - y.second)) << endl;
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