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
    for (auto &vl : v)
        cin >> vl;
    reverse(all(v));
    vector<int> dp(n, 1);
    multiset<pair<int, int>> ms;
    ms.insert({-v[0], dp[0]});
    for (int i = 1; i < n; i++)
    {
        auto it = ms.upper_bound({-v[i], -1});
        if (it != ms.end())
        {
            // cerr << i << " " << it->first << endl;
            dp[i] = max(dp[i], it->second + 1);
        }
        ms.insert({-v[i], dp[i]});
    }
    // for (auto vl : dp)
    //     cout << vl << " ";
    // cout << endl;
    cout << *max_element(all(dp)) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}