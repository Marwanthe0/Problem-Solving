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
int f(int i, vector<int> &v, vector<int> &dp) {
    if (i + 1 >= v.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ekta = INT_MAX, duita = INT_MAX;
    if (i + 1 < v.size()) {
        ekta = f(i + 1, v, dp) + abs(v[i] - v[i + 1]);
    }
    if (i + 2 < v.size()) {
        duita = f(i + 2, v, dp) + abs(v[i] - v[i + 2]);
    }
    return dp[i] = min(ekta, duita);
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> dp(n + 1, -1);
    int ans = f(0, v, dp);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}