#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1e9 + 7
#define M2 10056

#define N 1000
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
vector<int> dp;
vector<int> fact(N + 5, 0ll), ifact(N + 5, 0ll);
int pascal[1001][1001];
void pre() {
    for (int i = 0; i <= 1e3; i++) {
        for (int j = 0; j <= 1e3; j++) {
            if (j > i) {
                pascal[i][j] = 0;
            } else if (i == 0 || j == 0) {
                pascal[i][j] = 1;
            } else {
                pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
                pascal[i][j] %= M2;
            }
        }
    }
}

void pre2() {
    dp.assign(N + 1, 0);
    dp[0] = dp[1] = 1;
    dp[2] = 3;
    for (int n = 3; n <= N; n++) {
        for (int k = 1; k <= n; k++) {
            dp[n] = (dp[n] + (pascal[n][k] * dp[n - k]) % M2) % M2;
        }
    }
}
void marwan(int cs) {
    int x;
    cin >> x;
    cout << dp[x] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    pre2();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}