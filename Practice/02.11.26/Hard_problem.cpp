#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<int> a;
vector<string> v;
vector<vector<int>> dp;
bool f(string &a, string &b) {
    return a <= b;
}
int f(int i, bool cng) {
    if (i == n)
        return 0;
    if (dp[i][cng] != -1)
        return dp[i][cng];
    int ans = 1e16;
    if (i == 0) {
        ans = min(ans, f(i + 1, cng));
        ans = min(ans, a[i] + f(i + 1, !cng));
        return dp[i][cng] = ans;
    }
    if (cng) {
        string t = v[i - 1], tt = v[i];
        reverse(all(t));
        if (f(t, v[i]))
            ans = min(ans, f(i + 1, 0));
        reverse(all(tt));
        if (f(t, tt))
            ans = min(ans, a[i] + f(i + 1, 1));
    } else {
        string tt = v[i];
        if (f(v[i - 1], v[i]))
            ans = min(ans, f(i + 1, 0));
        reverse(all(tt));
        if (f(v[i - 1], tt))
            ans = min(ans, a[i] + f(i + 1, 1));
    }
    return dp[i][cng] = ans;
}
void marwan() {
    cin >> n;
    a.assign(n, 0);
    v.assign(n, string());
    dp.assign(n + 1, vector<int>(2, -1));
    for (auto &vl : a)
        cin >> vl;
    for (auto &s : v)
        cin >> s;
    int ans = f(0, 0);
    if (ans >= 1e16)
        minus;
    else
        cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}