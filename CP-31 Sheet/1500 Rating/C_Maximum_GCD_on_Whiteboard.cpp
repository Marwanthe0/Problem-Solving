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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan()
{
    int n, k, mx = INT_MIN;
    cin >> n >> k;
    vector<int> v(n);
    unordered_map<int, int> m;
    vector<int> ans;
    for (auto &vl : v)
    {
        cin >> vl;
        mx = max(mx, vl);
        m[vl]++;
    }
    sort(all(v));
    for (auto vl : v)
    {
        for (int i = 1; i * i <= vl; i++)
        {
            if (vl % i == 0)
            {
                ans.push_back(i);
                ans.push_back(vl / i);
            }
        }
    }
    make_unique(ans);
    // for (auto vl : ans)
    //     cerr << vl << " ";
    // cerr << endl;
    auto ok = [&](int x)
    {
        int count = 0;
        count += (m[x] + m[2 * x] + m[3 * x]);
        int idx = lower_bound(all(v), 4 * x) - v.begin();
        count += (n - idx);
        return (n - count) <= k;
    };
    int last = 1;
    for (int i = 1; i <= mx; i++)
    {
        if (ok(i))
            last = i;
    }
    cout << last << endl;
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