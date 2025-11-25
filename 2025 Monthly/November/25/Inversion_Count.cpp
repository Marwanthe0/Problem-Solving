#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    pbds<int> p;
    int ans = 0;
    for (auto vl : v)
    {
        int val = 0;
        if (!p.empty())
            val = p.size() - p.order_of_key(vl);
        ans += val;
        p.insert(vl);
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

// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// using namespace std;
// #define int long long
// #define M 1000000007
// #define N 1000000
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define forn for (int i = 0; i < n; i++)
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// template <typename T>
// using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// void marwan()
// {
//     int n, ans = 0;
//     cin >> n;
//     vector<int> v(n);
//     for (auto &vl : v)
//         cin >> vl;
//     pbds<int> p;
//     for (int i = 0; i < n; i++)
//     {
//         if (!p.empty())
//         {
//             ans += (p.size() - p.order_of_key(v[i]));
//         }
//         p.insert(v[i]);
//     }
//     cout << ans << endl;
// }
// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         marwan();
//     }
//     return 0;
// }