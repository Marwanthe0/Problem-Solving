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
vector<vector<int>> v(2023, vector<int>());
unordered_map<int, int> m;
vector<int> dp(1e6 + 10, -1);
int f(int i)
{
    if (i == 1)
    {
        return 1;
    }
    // cerr << i << " ";
    // cerr << i << " ";
    if (dp[i] != -1)
        return dp[i];
    if (i == v[m[i]].front())
    {
        int child = i - m[i];
        return dp[i] = i * 1ll * i + f(child);
    }
    else if (i == v[m[i]].back())
    {
        int child = i - (m[i] + 1);
        return dp[i] = i * 1ll * i + f(child);
    }
    else
    {
        int child1 = i - (m[i] + 1), child2 = child1 + 1;
        dp[i] = i * 1ll * i + f(child1) + f(child2);
        if (child1 == v[m[child1]].front() && child2 == v[m[child2]].back())
            dp[i] -= 1;
        else if (child1 == v[m[child1]].front())
            dp[i] -= f(child1 - m[child1]);
        else
            dp[i] -= f(child1 - (m[child1]));
        return dp[i];
    }
}
void marwan()
{
    int n;
    cin >> n;
    cout << f(n) << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x = 0, k = 0;
    for (int i = 1; i <= 1e6 + 50; i++)
    {
        v[x].push_back(i);
        m[i] = x;
        k++;
        if (k >= x + 1)
            k = 0, x++;
    }
    // for (int i = 0; i <= 10; i++)
    // {
    //     for (auto vl : v[i])
    //         cout << vl << " ";
    //     cout << endl;
    // }
    int t;
    cin >> t;
    while (t--)
    {
        marwan();
    }
    return 0;
}