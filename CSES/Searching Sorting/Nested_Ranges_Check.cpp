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
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(all(v), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
         { if (a.first.first == b.first.first) return a.first.second > b.first.second; return a.first.first < b.first.first; });
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x = v[i].first.first, y = v[i].first.second, idx = v[i].second;
        if (mx >= y)
            b[idx] = 1;
        mx = max(y, mx);
    }
    int mn = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = v[i].first.first, y = v[i].first.second, idx = v[i].second;
        if (y >= mn)
            a[idx] = 1;
        mn = min(mn, y);
    }
    for (auto vl : a)
        cout << vl << " ";
    cout << endl;
    for (auto vl : b)
        cout << vl << " ";
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}