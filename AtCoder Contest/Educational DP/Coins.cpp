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
int n;
vector<long double> v;
vector<vector<long double>> dp;
long double f(int i, int h) {
    if (i < 0) {
        if (h > (n / 2))
            return 1;
        else
            return 0;
    }
    if (dp[i][h] != -1)
        return dp[i][h];
    long double head = f(i - 1, h + 1) * v[i], tail = f(i - 1, h) * (1 - v[i]);
    return dp[i][h] = head + tail;
}
void marwan() {
    cin >> n;
    v.resize(n);
    for (auto &vl : v)
        cin >> vl;
    dp.resize(n, vector<long double>(n, -1));
    long double ans = f(n - 1, 0);
    cout << setprecision(10) << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}