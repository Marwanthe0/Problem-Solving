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
    vector<pair<pair<int, int>, int>> v(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    sort(all(v), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
         {if(a.first.second == b.first.second)
            return a.first.first < b.first.first;
        return a.first.second < b.first.second; });
    multiset<pair<int, int>> ms;
    ms.insert({v[0].first.second, 0});
    dp[0] = v[0].second;
    for (int i = 1; i < n; i++)
    {
        dp[i] = v[i].second;
        auto it = ms.lower_bound({v[i].first.first, -1});
        if (it != ms.begin())
        {
            it--;
            dp[i] = max(dp[i - 1], dp[i] + dp[it->second]);
        }
        else
            dp[i] = max(dp[i - 1], v[i].second);
        ms.insert({v[i].first.second, i});
    }
    cout << dp[n - 1] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}