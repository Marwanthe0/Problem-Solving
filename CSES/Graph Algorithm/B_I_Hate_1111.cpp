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
vector<int> v = {11, 111, 1111, 11111, 111111, 1111111, 11111111};
bool ans(int sum, int i, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (i < 0)
        return false;
    if(dp[sum][i] != )
    bool nibona = ans(sum, i - 1, dp), nibo = false;
    if (v[i] <= sum)
        nibo = ans(sum - v[i], i, dp);
    return nibo | nibona;
}
void marwan()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(6, -1));
    bool ans(n, 6, dp) << endl;
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