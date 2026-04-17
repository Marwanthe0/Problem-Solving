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
int dp[15][2][2][2];
vector<int> pten(15);
void pre() {
    pten[0] = 1;
    for (int i = 1; i < 15; i++)
        pten[i] = pten[i - 1] * 10;
}
int f(int i, bool ust, bool lst, bool lz, string &l, string &r, int d) {
    if (i == l.size())
        return 0;
    if (dp[i][ust][lst][lz] != -1)
        return dp[i][ust][lst][lz];
    int lim = (ust ? r[i] - '0' : 9), ans = 1e17;
    for (int k = (lst ? (l[i] - '0') : 0); k <= lim; k++) {
        bool nlz = lz & (k == 0);
        if (k == d && !nlz)
            continue;
        int x = f(i + 1, ust && k == (r[i] - '0'), lst && (k == l[i] - '0'), nlz, l, r, d);
        if (x != 1e17) {
            ans = min(ans, (k * pten[l.size() - 1 - i]) + x);
        }
    }
    return dp[i][ust][lst][lz] = ans;
}
void marwan() {
    int l, r, d;
    cin >> l >> r >> d;
    if (l > r) {
        minus;
        return;
    }
    string s = to_string(l), t = to_string(r);
    int n = max(s.size(), t.size());
    while (s.size() < n)
        s = "0" + s;
    while (t.size() < n)
        t = "0" + t;
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m < 2; m++)
                    dp[i][j][k][m] = -1;
            }
        }
    }
    int ans = f(0, 1, 1, 1, s, t, d);
    if (ans == 1e17)
        minus;
    else
        cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}