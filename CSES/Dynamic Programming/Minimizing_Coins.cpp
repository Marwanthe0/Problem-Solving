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
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    for (auto &coin : coins)
        cin >> coin;
    vector<int> dp(sum + 1, (int)1e8);
    dp[0] = 0ll;
    for (int s = 1; s <= sum; s++)
    {
        for (auto coin : coins)
        {
            if (coin <= s)
                dp[s] = (min(dp[s], 1 + dp[s - coin])) % M;
        }
    }
    if (dp[sum] == 1e8)
        cout << -1 << endl;
    else
        cout << dp[sum] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}