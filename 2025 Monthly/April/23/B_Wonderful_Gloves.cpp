// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define M 1000000007
// #define N 1000000
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define forn for (int i = 0; i < n; i++)
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// bool cmp(pair<int, int> a, pair<int, int> b) { return a.first + a.second > b.first + b.second; }
// void marwan()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<pair<int, int>> v(n);
//     for (auto &vl : v)
//         cin >> vl.first;
//     for (auto &vl : v)
//         cin >> vl.second;
//     int sum = 0;
//     sort(all(v), cmp);
//     for (int i = 0; i < n; i++)
//         sum += max(v[i].first, v[i].second);
//     for (int i = 0; i < k; i++)
//         sum += min(v[i].first, v[i].second);
//     cout << sum << endl;
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
// // #include <bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // #define M 1000000007
// // #define N 1000000
// // #define endl "\n"
// // #define all(v) v.begin(), v.end()
// // #define forn for (int i = 0; i < n; i++)
// // #define yes cout << "YES" << endl
// // #define no cout << "NO" << endl
// // void marwan()
// // {
// //     int n, k;
// //     cin >> n >> k;
// //     vector<int> a(n), b(n);
// //     for (auto &vl : a)
// //         cin >> vl;
// //     for (auto &vl : b)
// //         cin >> vl;
// //     int x = accumulate(all(a), 0ll), y = accumulate(all(b), 0ll);
// //     // sort(all(a));
// //     // sort(all(b));
// //     cout << min(x + accumulate(b.begin(), b.begin() + k, 0ll), y + accumulate(a.begin(), a.begin() + k, 0ll)) << endl;
// //     int sum = 0;
// //     for (int i = 0; i < n; i++)
// //         sum += max(a[i], b[i]);
// //     sort(all(a), greater<int>());
// //     sort(all(b), greater<int>());
// //     for (int i = 0; i < k; i++) sum += min()
// //         cerr << x << " " << y << endl;
// //     for (int i = 0; i < n; i++)
// //         cerr << a[i] + b[i] << " ";
// //     cerr << endl;
// // }
// // int32_t main()
// // {
// //     ios_base::sync_with_stdio(false);
// //     cin.tie(0);
// //     int t;
// //     cin >> t;
// //     while (t--)
// //     {
// //         marwan();
// //     }
// //     return 0;
// // }
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
    cin >> n >> k;
    vector<int> v(2 * n);
    for (auto &vl : v)
        cin >> vl;
    sort(all(v), greater<int>());
    vector<int> t = v;
    sort(all(t));
    cout << accumulate(v.begin(), v.begin() + n, 0ll) + accumulate(t.begin(), t.begin() + k, 0ll) << endl;
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