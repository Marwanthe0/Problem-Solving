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
int dp[100][2][2];
int f(int i, bool ltight, bool htight, string &a, string &b) {
    if (i == a.size())
        return 0;

    if (dp[i][ltight][htight] != -1)
        return dp[i][ltight][htight];
    int lowlim = ltight ? (a[i] - '0') : 0, lim = htight ? (b[i] - '0') : 9, ans = 1e8;

    for (int j = lowlim; j <= lim; j++) {
        int x = (j == (a[i] - '0')) + (j == (b[i] - '0'));
        x += f(i + 1, ltight && j == lowlim, htight && j == lim, a, b);
        ans = min(ans, x);
    }
    return dp[i][ltight][htight] = ans;
}
void marwan() {
    int l, r;
    cin >> l >> r;
    string a = to_string(l), b = to_string(r), s;
    int n = max((int)a.size(), (int)b.size());
    while ((int)a.size() != n)
        a = "0" + a;
    while ((int)b.size() != n)
        b = "0" + b;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout << f(0, 1, 1, a, b) << endl;
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