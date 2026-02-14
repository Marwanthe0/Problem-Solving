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
vector<string> ans;
void f(int i, int sum, int d, string &s, vector<vector<vector<int>>> &dp)
{
    if (i < 0)
    {
        if (sum == 0 && s.back() != '0')
        {
            reverse(all(s));
            ans.push_back(s);
        }
        return;
    }
    else if (sum <= 0)
        return;
    if (dp[i][sum][d] != -1)
        return;
    if (d > 0)
        f(i, sum, d - 1, s, dp);
    if (sum >= d)
    {
        s.push_back(d + '0');
        f(i - 1, sum - d, min(9ll, sum - d), s, dp);
        s.pop_back();
    }
    dp[i][sum][d] = 1;
    return;
}
void marwan()
{
    int n, sum;
    cin >> n >> sum;
    string s;
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(sum + 1,
                                                       vector<int>(10, -1)));
    f(n - 1, sum, 9, s, dp);
    // for (auto vl : ans)
    //     cout << vl << endl;
    if (ans.empty())
        cout << -1 << " " << -1 << endl;
    else
    {
        sort(all(ans));
        cout << ans.front() << " " << ans.back() << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}