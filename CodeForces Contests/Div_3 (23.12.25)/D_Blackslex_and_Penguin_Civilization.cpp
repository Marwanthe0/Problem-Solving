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
// int bt(int n)
// {
//     int count = 0;
//     for (int i = 0; i <= __lg(n); i++)
//     {
//         count += ((n >> i) & 1);
//     }
//     return count;
// }
// void marwan()
// {
//     int n;
//     cin >> n;
//     map<int, vector<int>> m;
//     for (int i = 0; i < (1 << n); i++)
//     {
//         int count = bt(i);
//         m[count].push_back(i);
//     }
//     vector<pair<int, vector<int>>> ans;
//     for (auto vl : m)
//     {
//         ans.push_back(vl);
//     }
//     reverse(all(ans));
//     // sort(all(ans));
//     vector<int> last;
//     int xx = (~(0ll));
//     set<int> check;
//     bool flag = true;
//     for (auto vl : ans)
//     {
//         sort(all(vl.second));
//         if (flag == false)
//             break;
//         for (auto val : vl.second)
//         {
//             xx = (xx & val);
//             if (xx)
//             {
//                 last.push_back(val);
//                 check.insert(val);
//             }
//             else
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     for (auto vl : last)
//         cout << vl << " ";
//     for (int i = 0; i < (1 << n); i++)
//     {
//         if (check.find(i) == check.end())
//             cout << i << " ";
//     }
//     cout << endl;
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
    int n;
    cin >> n;
    vector<int> v;
    set<int> s;
    for (int i = n; i >= 0; i--)
    {
        int x = (1ll << i) - 1;
        v.push_back(x);
        s.insert(x);
    }
    for (auto vl : v)
        cout << vl << " ";
    for (int i = 0; i < (1ll << n); i++)
    {
        if (s.find(i) == s.end())
            cout << i << " ";
    }
    cout << endl;
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