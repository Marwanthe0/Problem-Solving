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
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}
void marwan()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> v(n), mod;
    vector<pair<pair<int, int>, int>> a, b;
    map<pair<int, int>, int> m;
    for (auto &vl : v)
    {
        cin >> vl;
        a.push_back({{vl % x, vl % y}, vl});
        m[{vl % x, vl % y}]++;
        mod.push_back(vl % x);
    }
    sort(all(a), cmp);
    int count = 0;
    for (auto vl : a)
    {
        int find = (x - vl.first.first) % x;
        count += m[{find, vl.first.second}];
        if (find == vl.first.first)
            count--;
    }
    cout << count / 2 << endl;
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