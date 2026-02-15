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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), zer;
    vector<pair<int, int>> v(m), t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> v[i].first;
    for (int i = 0; i < m; i++)
        cin >> v[i].second;
    multiset<int> ms(all(a));
    for (auto [x, y] : v)
    {
        if (y)
            t.push_back({x, y});
        else
            zer.push_back(x);
    }
    sort(all(t));
    int idx = 0;
    for (int i = 0; i < t.size(); i++)
    {
        auto it = ms.lower_bound(t[i].first);
        if (it == ms.end())
            break;
        else
        {
            ms.insert(max(*it, t[i].second));
            ms.erase(it);
            idx++;
        }
    }
    a.clear();
    for (auto vl : ms)
        a.push_back(vl);
    sort(all(zer));
    sort(all(a));
    int l = 0, r = 0;
    while (r < zer.size())
    {
        while (l < a.size() && a[l] < zer[r])
            l++;
        if (l < a.size() && a[l] >= zer[r])
            idx++, l++;
        r++;
    }
    cout << idx << endl;
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