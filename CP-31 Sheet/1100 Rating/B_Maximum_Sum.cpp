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
    vector<int> v(n), t;
    for (auto &vl : v)
        cin >> vl;
    sort(all(v));
    for (int i = 0; i < n - 1; i += 2)
    {
        t.push_back(v[i] + v[i + 1]);
    }
    reverse(all(v));
    vector<int> pf(v.size() + 1, 0), pf2(t.size() + 1, 0);
    // for (auto vl : v)
    //     cout
    //         << vl << " ";
    // cout << endl;
    // for (auto vl : t)
    //     cout << vl << " ";
    // cout << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i <= t.size())
        {
            pf2[i] = pf2[i - 1] + t[i - 1];
        }
        pf[i] = pf[i - 1] + v[i - 1];
    }
    // for (auto vl : pf)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : pf2)
    //     cerr << vl << " ";
    // cerr << endl;
    int sum = accumulate(all(v), 0ll);
    int ans = 1e18;
    for (int i = 0; i <= k; i++)
    {
        int a = pf[i], b = pf2[k - i];
        ans = min(ans, a + b);
    }
    cout << sum - ans << endl;
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