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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    for (int i = 0; i < n; i++)
    {
        int p = a[i];
        vector<pair<int, int>> v;
        for (auto vl : a)
        {
            v.push_back({abs(p - vl), vl});
        }
        sort(all(v));
        vector<int> t;
        for (auto vl : v)
            t.push_back(vl.second);
        // cerr << endl;
        if (t == b)
        {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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