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
    int n;
    cin >> n;
    vector<pair<int, int>> v, t;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < (i + 1))
        {
            v.push_back({x, i + 1});
            t.push_back({i + 1, x});
        }
    }
    sort(all(v));
    pbds<int> p;
    int ans = 0;
    for (auto [x, y] : v)
    {
        p.insert(y);
        ans += p.order_of_key(x);
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