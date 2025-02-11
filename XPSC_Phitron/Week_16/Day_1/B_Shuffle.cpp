#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    int n, x, m;
    cin >> n >> x >> m;
    vector<pair<int, int>> v(m);
    for (auto &[a, b] : v)
        cin >> a >> b;
    map<pair<int, int>, int> mp;
    for (auto &[a, b] : v)
    {
        if (x >= a && x <= b)
        {
            mp[{a, b}] = 1;
        }
        else
        {
            for (auto vl : mp)
            {
                if (vl.second == 1 && ((vl.first.first <= b && vl.first.first >= a) || (vl.first.second <= b && vl.first.second >= a)))
                {
                    mp[{a, b}] = 1;
                    break;
                }
            }
            if (mp.find({a, b}) == mp.end())
                mp[{a, b}] = 0;
        }
    }
    int f = INT_MAX, l = INT_MIN;
    for (auto vl : mp)
    {
        if (vl.second)
            f = min(f, vl.first.first), l = max(l, vl.first.second);
    }
    cout << max(l - f + 1, 1ll) << endl;
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