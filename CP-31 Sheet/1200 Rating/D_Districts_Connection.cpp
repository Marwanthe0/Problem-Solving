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
// void marwan()
// {
//     int n;
//     cin >> n;
//     map<int, int> m;
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         m[i + 1] = x;
//     }
//     vector<pair<int, int>> mr;
//     set<int> check;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j < i; j++)
//         {
//             if (m[i] != m[j])
//             {

//                 int first = i, second = j;
//                 if (check.find(first) != check.end() && check.find(second) != check.end())
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     mr.push_back({j, i});
//                     check.insert(first);
//                     check.insert(second);
//                 }
//             }
//         }
//     }
//     // sort(all(ans));
//     // set<int> check;
//     // for (int i = 0; i < ans.size(); i++)
//     // {
//     //     int first = ans[i].first, second = ans[i].second;
//     //     if (check.find(first) != check.end() && check.find(second) != check.end())
//     //     {
//     //         continue;
//     //     }
//     //     else
//     //     {
//     //         mr.push_back(ans[i]);
//     //         check.insert(first);
//     //         check.insert(second);
//     //     }
//     // }
//     if (mr.size() < n - 1)
//     {
//         no;
//     }
//     else
//     {
//         yes;
//         for (auto vl : mr)
//             cout << vl.first << " " << vl.second << endl;
//         cout << endl;
//     }
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
    vector<int> v(n);
    map<int, int> m, p;
    for (int i = 1; i <= n; i++)
    {
        int vl;
        cin >> vl;
        m[i] = vl;
        p[vl]++;
    }
    if (p.size() == 1)
    {
        no;
        return;
    }
    int first = -1;
    yes;
    for (int i = 2; i <= n; i++)
    {
        if (m[i] != m[1])
        {
            cout << 1 << " " << i << endl;
            if (first == -1)
                first = i;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (m[i] == m[1])
            cout << i << " " << first << endl;
    }
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