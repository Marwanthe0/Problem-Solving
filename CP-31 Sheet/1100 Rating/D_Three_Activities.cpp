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
    int n, ans = 0ll;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for (auto &vl : v)
        cin >> vl.first;
    for (auto &vl : v)
        cin >> vl.second.first;
    for (auto &vl : v)
        cin >> vl.second.second;
    sort(all(v), greater<pair<int, pair<int, int>>>());
    for (int i = 0; i < 3; i++)
    {
        int x = v[i].first;
        vector<pair<int, int>> t;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
                t.push_back({v[j].second.first, v[j].second.second});
        }
        sort(all(t), greater<pair<int, int>>());
        for (int j = 0; j < min(3ll, n - 1); j++)
        {
            int y = t[j].first;
            vector<int> d;
            for (int k = 0; k < t.size(); k++)
            {
                if (k != j)
                {
                    d.push_back(t[k].second);
                }
            }
            sort(all(d), greater<int>());
            for (int k = 0; k < min(3ll, n - 2); k++)
            {
                ans = max(ans, x + y + d[k]);
            }
        }
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