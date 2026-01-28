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
    vector<pair<pair<int, int>, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i + 1;
    }
    sort(all(v), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
         {if(a.first.first == b.first.first) return a.first.second > b.first.second; return a.first.first < b.first.first; });
    pair<int, int> mx = {INT_MIN, 0};
    for (auto [x, y] : v)
    {
        if (mx.first >= x.second)
        {
            cout << y << " " << mx.second;
            return;
        }
        if (x.second > mx.first)
            mx.first = x.second, mx.second = y;
    }
    cout << -1 << " " << -1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}