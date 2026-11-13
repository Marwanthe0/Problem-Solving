#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int d, n;
string s;
vector<vector<int>> dp;
vector<int> fact;
int f(int mask, int sum) {
    if (mask == (1 << n) - 1)
        return sum == 0;
    if (dp[mask][sum] != -1)
        return dp[mask][sum];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1LL)
            continue;
        int dig = s[i] - '0';
        int tmask = mask | (1 << i);
        int tsum = (sum * 10 + dig) % d;
        ans += f(tmask, tsum);
    }
    return dp[mask][sum] = ans;
}
void marwan(int cs) {
    cin >> s;
    cin >> d;
    n = s.size();
    int msk = (1ll << n);
    dp.assign(msk, vector<int>(d + 1, -1));
    int ans = f(0, 0);
    map<char, int> m;
    for (auto c : s)
        m[c]++;
    for (auto [x, y] : m) {
        ans /= fact[y];
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact.assign(11, 0);
    fact[0] = 1;
    for (int i = 1; i <= 10; i++)
        fact[i] = fact[i - 1] * i;
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}