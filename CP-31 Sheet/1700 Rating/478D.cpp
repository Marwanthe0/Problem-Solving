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
// int f(int r, int g, int y) {
//     if (y == 0)
//         return 1;
//     int ans = 0ll;
//     if (r >= y)
//         ans += f(r - y, g, y - 1);
//     if (g >= y)
//         ans += f(r, g - y, y - 1);
//     return ans;
// }
// vector<vector<int>> dp;
// int f2(int r, int y, int extra) {
//     // cerr << r << " " << y << " " << extra << endl;
//     if (y == 0)
//         return 1;
//     int ans = 0ll, g = (y * (y + 1) / 2) - r + extra;
//     if (dp[r][y] != -1)
//         return dp[r][y];
//     // cerr << r << " " << g << " " << y << endl;
//     if (r >= y) {
//         ans = (ans + f2(r - y, y - 1, extra)) % M;
//     }
//     if (g >= y) {
//         ans = (ans + f2(r, y - 1, extra)) % M;
//     }
//     return dp[r][y] = ans % M;
// }
void marwan() {
    int r, g;
    cin >> r >> g;
    if (r > g)
        swap(r, g);
    int x = r + g;
    int sum = 0, y = 0;
    while (sum <= x) {
        y++;
        sum += y;
    }
    y--;
    // cout << y << endl;
    int extra = (r + g) - (y * (y + 1) / 2);
    vector<int> prev(r + 1, 1), next(r + 1, 0);
    for (int i = 1; i <= y; i++) {
        for (int j = 0; j <= r; j++) {
            int g = (i * (i + 1) / 2) - j + extra;
            if (j >= i) {
                next[j] += (prev[j - i]) % M;
                next[j] %= M;
            }
            if (g >= i) {
                next[j] += (prev[j] % M);
                next[j] %= M;
            }
            next[j] %= M;
        }
        prev = next;
        for (int j = 0; j <= r; j++)
            next[j] = 0;
    }
    cout << prev[r] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}