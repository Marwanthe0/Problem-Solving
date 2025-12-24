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
    cin >> n;
    // vector<pair<int, int>> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i].first;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i].second;
    // }
    vector<int>
        v(n),
        c(n);
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : c)
        cin >> vl;
    int ls = INT_MAX, ans = 0;
    for (int i = 0; i < n; i++)
    {
        ls = min(ls, c[i]);
        ans += ls * v[i];
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