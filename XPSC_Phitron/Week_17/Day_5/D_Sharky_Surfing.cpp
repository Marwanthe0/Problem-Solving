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
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
void marwan()
{
    int n, m, l;
    cin >> n >> m >> l;
    vector<pair<int, int>> v(n), a(m);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    for (auto &vl : a)
        cin >> vl.first >> vl.second;
    sort(all(a), cmp);
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first > v[l].first)
        {
            
        }
    }
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