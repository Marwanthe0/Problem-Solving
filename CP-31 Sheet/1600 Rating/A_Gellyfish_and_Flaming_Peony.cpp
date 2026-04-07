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
int f(int i, int g, vector<int> &v, int target, vector<vector<int>> &dp) {
    if (g == target)
        return 0;
    if (i < 0)
        return INT_MAX;
    if (dp[i][g] != -1)
        return dp[i][g];
    int nibona = f(i - 1, g, v, target, dp), nibo = 1 + f(i - 1, __gcd(v[i], g), v, target, dp);
    return dp[i][g] = min(nibo, nibona);
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    int g = 0;
    for (auto &vl : v) {
        cin >> vl;
        g = __gcd(vl, g);
    }
    sort(all(v));
    if (count(all(v), g)) {
        int count = 0;
        for (auto vl : v)
            count += (vl != g);
        cout << count << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (__gcd(v[i], v[j]) == g) {
                cout << n << endl;
                return;
            }
        }
    }
    vector<vector<int>> dp(n + 1, vector<int>(5001, -1));
    int ans = f(n - 1, 0, v, g, dp);
    cout << (n - 1) + (ans - 1) << endl;
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