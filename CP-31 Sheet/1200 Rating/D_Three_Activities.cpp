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
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return max({a.first, a.second.first, a.second.second}) > max({b.first, b.second.first, b.second.second});
}
void marwan()
{
    int n;
    cin >> n;
    // vector<pair<int, pair<int, int>>> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i].first;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i].second.first;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i].second.second;
    // }
    // sort(all(v), cmp);
    // int ans = 0;
    // for (int i = 0; i < 3; i++)
    // {
    //     ans += max({v[i].first, v[i].second.first, v[i].second.second});
    // }
    // cout << ans << endl;
    // for (auto vl : v)
    //     cerr << vl.first << " " << vl.second.first << " " << vl.second.second << endl;
    // cerr << endl;
    vector<vector<int>> v(3, vector<int>(n, 0));
    for (auto &row : v)
    {
        for (auto &vl : row)
            cin >> vl;
    }
    vector<int> a(all(v[0])), b(all(v[1])), c(all(v[2]));
    sort(all(a));
    
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