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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> t(m);
        for (auto &vl : t)
            cin >> vl;
        sort(all(t));
        v[i] = {t[0], t[1]};
    }
    sort(all(v), cmp);
    // for (auto [x, y] : v)
    //     cout << x << " " << y << endl;
    // cout << endl;
    int ans = 0;
    int mn = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        ans += v[i].second;
        mn = min(mn, v[i].first);
    }
    cout << ans + min(mn, v.back().first) << endl;
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