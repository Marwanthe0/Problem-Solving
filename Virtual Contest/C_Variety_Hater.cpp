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
    vector<int> v(n);
    // set<int> s;
    // map<int, int> m;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    //     m[v[i]]++;
    //     s.insert(v[i]);
    // }
    // vector<int> a;
    // for (auto vl : s)
    //     a.push_back(vl);
    // // for (auto vl : a)
    // //     cout << vl << " ";
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] != v[i])
            {
                ms.insert(v[j] - v[i]);
            }
        }
    }
    // for (int i = 1; i < a.size(); i++)
    // {
    //     while (m[a[i]])
    //         ms.insert(a[i] - a[i - 1]), m[a[i]]--;
    // }
    vector<int> x(all(ms));
    if (x.size())
        cerr << x[0] << " ";
    for (int i = 1; i < x.size(); i++)
    {
        // x[i] += x[i - 1];
        cerr << x[i] << " ";
    }
    cerr << endl;
    // int ans = s.size();
    // if (!x.empty())
    //     ans -= ((lower_bound(all(x), k) - x.begin()) + 1);
    // cout << max(1ll, ans) << endl;
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