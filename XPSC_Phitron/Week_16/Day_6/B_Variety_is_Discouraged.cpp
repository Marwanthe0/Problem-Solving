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
    map<int, int> m, dp;
    for (auto &vl : v)
    {
        cin >> vl;
        m[vl]++;
    }
    for (auto vl : m)
        if (vl.second > 1)
            dp[vl.first]++;
    int mx = INT_MIN, count = 0, last = 0;
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (dp.find(v[i]) == dp.end())
        {
            count++;
            if (count >= mx)
            {
                mx = count;
                ans = {last + 1, i + 1};
            }
        }
        else
            count = 0, last = i + 1;
    }
    if (mx != INT_MIN)
        cout << ans.first << " " << ans.second << endl;
    else
        cout << 0 << endl;
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