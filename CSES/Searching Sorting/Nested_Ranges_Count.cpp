#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
void marwan()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n);
    vector<int> a(n, 0), b(n, 0);
    pbds<int> pb1, pb2;
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
        // if (mx >= y)
        //     b[idx] = 1;
        b[idx] += pb2.order_of_key(-y + 1);
        // mx = max(y, mx);
        pb2.insert(-y);
    }
    int mn = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        int x = v[i].first.first, y = v[i].first.second, idx = v[i].second;
        // if (y >= mn)
        //     a[idx] = 1;
        a[idx] += pb1.order_of_key(y + 1);
        // mn = min(mn, y);
        pb1.insert(y);
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