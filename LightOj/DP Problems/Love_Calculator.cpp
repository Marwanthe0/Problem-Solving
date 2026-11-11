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
string a, b;
int n, m;
vector<vector<pair<int, int>>> dp;
pair<int, int> f(int i, int j) {
    if (i == n)
        return {m - j, 1};
    if (j == m)
        return {n - i, 1};
    if (dp[i][j].first != -1)
        return dp[i][j];
    pair<int, int>
        ans = {1e9, 0};
    if (a[i] == b[j]) {
        pair<int, int> tans = f(i + 1, j + 1);
        tans.first += 1;
        if (tans.first < ans.first) {
            ans = tans;
        }
    } else {
        pair<int, int> tans2 = f(i + 1, j), tans3 = f(i, j + 1);
        tans2.first += 1;
        tans3.first += 1;
        if (tans2.first < ans.first)
            ans = tans2;
        else if (tans2.first == ans.first)
            ans.second += tans2.second;

        if (tans3.first < ans.first)
            ans = tans3;
        else if (tans3.first == ans.first)
            ans.second += tans3.second;
    }
    return dp[i][j] = ans;
}
void marwan(int cs) {
    cin >> a;
    cin >> b;
    n = a.size(), m = b.size();
    dp.assign(n + 1, vector<pair<int, int>>(m + 1, {-1, -1}));
    pair<int, int> ans = f(0, 0);
    cout << ans.first << " " << ans.second << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}