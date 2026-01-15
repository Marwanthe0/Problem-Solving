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
int ans(vector<int> &v, int i, unordered_map<int, int> &dp)
{
    if (i >= v.size())
        return 0;
    if (dp.find(i) != dp.end())
        return dp[i];
    int mx = ans(v, i + 1, dp);
    if (i + v[i] < v.size())
    {
        mx = max(mx, ans(v, i + v[i] + 1, dp) + v[i] + 1);
    }
    return dp[i] = mx;
}
void marwan()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    unordered_map<int, int> dp;
    cout << n - ans(v, 0, dp) << endl;
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