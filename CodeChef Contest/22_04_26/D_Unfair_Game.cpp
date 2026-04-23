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
int dp[33][2][2][2][33][33];
int f(int i, bool lst, bool ust, bool lz, int zerocount, int onecount, string &l, string &r, int thres) {
    if (i == l.size()) {
        return (lz == 0 && (zerocount + (2 * onecount)) > thres);
    }
    if (dp[i][lst][ust][lz][zerocount][onecount] != -1)
        return dp[i][lst][ust][lz][zerocount][onecount];
    int llim = lst ? l[i] - '0' : 0, lim = ust ? r[i] - '0' : 1;
    int ans = 0ll;
    for (int k = llim; k <= lim; k++) {
        bool nlz = lz & (k == 0);
        int zn = zerocount, on = onecount;
        if (!nlz) {
            if (k == 1)
                on = onecount + 1;
            else
                zn = zerocount + 1;
        }
        ans += f(i + 1, lst & (k == llim), ust & (k == lim), nlz, zn, on, l, r, thres);
    }
    return dp[i][lst][ust][lz][zerocount][onecount] = ans;
}
void marwan() {
    int n, k;
    cin >> n >> k;
    // for (int i = 1; i <= n; i++) {
    //     if (__lg(i) + __builtin_popcount(i) > k)
    //         count++;
    //     cerr << i << " " << __lg(i) << endl;
    // }
    // cout << count << endl;
    // k = min(k, 2 * __lg(n));
    string s;
    int mx = __lg(n);
    for (int i = mx; i >= 0; i--) {
        if ((1 & (n >> i)))
            s.push_back('1');
        else
            s.push_back('0');
    }
    string l = "1";
    int sz = s.size();
    while (l.size() < sz)
        l = "0" + l;
    // cerr << l << " " << s << endl;
    int oc = sz;
    int zc = sz;
    for (int a = 0; a <= sz; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d < 2; d++) {
                    for (int e = 0; e <= zc; e++) {
                        for (int f = 0; f <= oc; f++) {
                            dp[a][b][c][d][e][f] = -1;
                        }
                    }
                }
            }
        }
    }
    int ans = f(0, 1, 1, 1, 0, 0, l, s, k + 1);
    cout << ans << endl;
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