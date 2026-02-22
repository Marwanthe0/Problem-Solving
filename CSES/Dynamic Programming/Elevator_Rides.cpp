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
    for (auto &vl : v)
        cin >> vl;
    vector<pair<int, int>> dp(1 << n, {0, 0});
    // dp[i] = by taking mask[i] people what is the minimum rides + minimum weights
    dp[0] = {1, 0};
    // for (int i = 1; i < (1 << n); i *= 2)
    //     dp[i] = {1, 0};
    for (int i = 1; i < (1 << n); i++)
    {
        pair<int, int> mn = {INT_MAX, INT_MAX};
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                int x = i ^ (1 << j);
                pair<int, int> a = dp[x];
                if (dp[x].second + v[j] <= k)
                    a.second += v[j];
                else
                    a.second = v[j], a.first++;
                if (a.first < mn.first || (a.first == mn.first && a.second < mn.second))
                    mn = a;
            }
        }
        dp[i] = mn;
    }
    // for (int i = 0; i < (1 << n); i++)
    //     cerr << dp[i].first << " " << dp[i].second << endl;
    cout << dp[(1 << n) - 1].first << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}