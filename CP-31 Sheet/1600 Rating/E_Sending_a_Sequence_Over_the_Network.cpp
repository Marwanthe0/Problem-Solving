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
bool f(int i, int due, vector<int> &v, map<pair<int, int>, bool> &dp) {
    if (i < 0)
        return i == -1 && due == 0;
    if (dp.count({i, due}))
        return dp[{i, due}];
    bool x = f(i - v[i] - 1, due, v, dp);
    bool y = f(i - 1, v[i] == due ? 0 : due + 1, v, dp);
    return dp[{i, due}] = x || y;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n + 1, 0), isans(n + 2, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    isans[0] = 1;
    auto valid = [&](int x) { return x >= 0 && x <= n; };
    for (int i = 1; i <= n; i++) {
        int x = v[i];
        if (isans[i - 1] && valid(i + x))
            isans[i + x] = 1;
        if (valid(i - x - 1) && isans[i - x - 1])
            isans[i] = 1;
    }
    if (isans[n])
        yes;
    else
        no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}