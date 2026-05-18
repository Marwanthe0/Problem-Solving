#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
int n;
vector<int> v;
// int f(int i, bool cooldown, int red) {
//     if (i == n)
//         return 1;
//     if (dp[i][cooldown][red] != -1)
//         return dp[i][cooldown][red];
//     int ans = 0;
//     if (v[i] == red) {
//         ans = (ans + f(i + 1, 0, red)) % M;
//     }
//     if (!cooldown) {
//         ans = (ans + f(i + 1, 1, red + 1)) % M;
//     }
//     return dp[i][cooldown][red] = ans % M;
// }
void marwan() {
    cin >> n;
    v.resize(n);
    for (auto &vl : v)
        cin >> vl;
    // int ans = f(0, 0, 0);
    int tp[n + 1][2][(n / 2) + 3];
    memset(tp, 0, sizeof(tp));
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < (n / 2) + 3; k++)
            tp[n][j][k] = 1;
    }
    int next[2][(n / 2) + 1], prev[2][(n / 2) + 1];
    memset(next, 0, sizeof(next));
    memset(prev, 1, sizeof(prev));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j >= 0; j--) {
            for (int k = (n / 2) + 1; k >= 0; k--) {
                if (j == 0) {
                    tp[i][j][k] += tp[i + 1][1][k + 1];
                    // next[j][k] += prev[1][k + 1];
                }
                if (v[i] == k) {
                    tp[i][j][k] += tp[i + 1][0][k];
                    // next[j][k] += prev[0][k];
                }
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j >= 0; j--) {
            for (int k = (n / 2) + 1; k >= 0; k--) {
                if (j == 0) {
                    // tp[i][j][k] += tp[i + 1][1][k + 1];
                    next[j][k] += prev[1][k + 1];
                }
                if (v[i] == k) {
                    // tp[i][j][k] += tp[i + 1][0][k];
                    next[j][k] += prev[0][k];
                }
            }
        }
    }
    cout << tp[0][0][0] << endl;
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