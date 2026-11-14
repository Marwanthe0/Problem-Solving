// //Using DP

// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define M 1000000007
// #define N 1000005
// #define INF 1e17
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define minus cout << "-1" << endl
// #define zero cout << "0" << endl
// #define make_unique(x) \
//     sort(all((x)));    \
//     (x).erase(unique(all((x))), (x).end())
// int dp[51][51][51];
// int f(int n, int k, int m) {
//     if (n == 0)
//         return k == 0;
//     if (n < 0 || k < 0)
//         return 0;
//     if (dp[n][k][m] != -1)
//         return dp[n][k][m];
//     int ans = 0;
//     for (int len = 1; len <= m; len++)
//         ans += f(n - len, k - 1, m);
//     return dp[n][k][m] = ans;
// }
// void marwan(int cs) {
//     int n, k, m;
//     cin >> n >> k >> m;
//     int ans = f(n, k, m);
//     cout << ans << endl;
// }
// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     memset(dp, -1, sizeof(dp));
//     int t;
//     cin >> t;
//     for (int i = 1; i <= t; i++) {
//         cout << "Case " << i << ": ";
//         marwan(i);
//     }
//     return 0;
// }

// Using Combinatorics
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define N 51
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
int ncr[51][51];
void pre() {
    memset(ncr, 0, sizeof ncr);
    ncr[0][0] = 1;
    for (int n = 1; n <= 50; n++) {
        ncr[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            ncr[n][k] = ncr[n - 1][k - 1] + ncr[n - 1][k];
        }
    }
}
int nCr(int n, int k) {
    return ncr[n][k];
}
void marwan(int cs) {
    int n, k, m;
    cin >> n >> k >> m;
    int stars = n, box = k, bars = k - 1;
    // give 1 star to each box k
    stars -= k;
    int total = nCr(stars + bars, bars);
    int ml = -1, x = 1;
    while (x * m <= stars) {
        // remaining stars after giving m stars to x boxes
        int rem_stars = stars - (x * m);
        // way to choos those x boxes
        int box_ways = nCr(box, x);
        // ways to include/exclude
        int ways = nCr(rem_stars + bars, bars) * box_ways;
        total = (total + ml * ways);
        ml *= -1, x++;
    }
    cout << total << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}