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
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second - a.first > b.second - b.first; }
void marwan()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first;
    for (int i = 0; i < n; i++)
        cin >> v[i].second;

    vector<int> a;
    sort(all(v), cmp);
    for (auto [x, y] : v)
    {
        a.push_back(y - x);
        // cerr << a.back() << " ";
    }
    // cerr << endl;
    int l = 0, r = n - 1, ans = 0;
    while (l < r)
    {
        while (((-1) * a[r]) > a[l])
            r--;
        if (l < r)
            ans++, l++, r--;
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