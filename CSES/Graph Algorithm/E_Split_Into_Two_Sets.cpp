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
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v)
        cin >> x >> y;
    set<int> s, s1;
    int ans = 0;
    for (auto [x, y] : v)
        if (x == y)
        {
            no;
            return;
        }
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        auto [x, y] = v[i];
        if (s.count(x) || s.count(y))
            continue;
        else
        {
            s.insert(x);
            s.insert(y);
            vis[i] = 1;
            ans++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i])
            continue;
        auto [x, y] = v[i];
        if (s1.count(x) || s1.count(y))
        {
            no;
            return;
        }
        else
        {
            s1.insert(x);
            s1.insert(y);
        }
    }
    yes;
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