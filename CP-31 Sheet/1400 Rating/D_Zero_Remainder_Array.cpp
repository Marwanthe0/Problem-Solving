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
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x % k)
            v.push_back(k - (x % k));
    }
    if (all_of(all(v), [&](int x)
               { return x == 0; }))
    {
        cout << 0 << endl;
        return;
    }
    sort(all(v));
    map<int, int> m;
    for (auto &vl : v)
    {
        // cout << vl << " ";
        m[vl]++;
    }
    int mx = 0, mxidx;
    for (auto [x, y] : m)
    {
        if (y >= mx)
            mx = y, mxidx = x;
    }
    cout << (k * (mx - 1)) + mxidx + 1 << endl;
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