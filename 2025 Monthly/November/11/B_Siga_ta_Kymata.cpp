#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
    vector<pair<int, int>> left(n), right(n);
    for (auto &vl : v)
        cin >> vl;
    string x;
    cin >> x;
    left[0] = {0, 0}, right[n - 1] = {n - 1, n - 1};
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[left[i - 1].first])
        {
            left[i].first = i;
        }
        else
            left[i].first = left[i - 1].first;
        if (v[i] > v[left[i - 1].second])
        {
            left[i].second = v[i];
        }
        else
            left[i].second = left[i - 1].second;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        // if (v[i] > v[right[i + 1]])
        // {
        //     right[i] = i;
        // }
        // else
        //     right[i] = right[i + 1];

        if (v[i] < v[right[i + 1].first])
        {
            right[i].first = i;
        }
        else
            right[i].first = right[i + 1].first;
        if (v[i] > v[right[i - 1].second])
        {
            right[i].second = v[i];
        }
        else
            right[i].second = right[i + 1].second;
    }
    for (auto vl : left)
        cerr << vl.first << " " << vl.second << endl;
    cerr << endl;
    for (auto vl : right)
        cerr << vl.first << " " << vl.second << endl;
    cerr << endl;
    set<pair<int, int>> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == 0 || i == n - 1)
    //     {
    //         if (x[i] == '1')
    //         {
    //             cout << -1 << endl;
    //             return;
    //         }
    //     }
    //     else
    //     {
    //         if (x[i] == '1')
    //         {
    //             if (v[i] > v[left[i]] && v[i] < v[right[i]])
    //             {
    //                 ans.insert({left[i] + 1, right[i] + 1});
    //             }
    //             else
    //             {
    //                 cout << -1 << endl;
    //                 return;
    //             }
    //         }
    //     }
    // }
    // cout << ans.size() << endl;
    // for (auto vl : ans)
    //     cout << vl.first << " " << vl.second << endl;
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