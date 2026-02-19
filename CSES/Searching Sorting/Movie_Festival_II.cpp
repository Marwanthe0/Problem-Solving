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
    vector<pair<int, int>> v(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        if (i < k)
            ms.insert(0);
    }
    sort(all(v), [&](pair<int, int> a, pair<int, int> b)
         {if(a.second == b.second)
            return a.first < b.first;
        return a.second < b.second; });
    int count = 0;
    for (auto &[x, y] : v)
    {
        auto it = ms.lower_bound(-x);
        if (it != ms.end() && *it >= -x)
        {
            ms.erase(it);
            ms.insert(-y);
            count++;
        }
    }
    cout << count << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}