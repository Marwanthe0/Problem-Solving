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
string l, r;
int n, k, d;
int dp1[100][2][2][100][1 << 10], dp2[100][2][2][100][1 << 10];
int f(int i, bool up, bool lz, int tk, int mask, string &s, bool first) {
    if (i == s.size()) {
        return 1;
    }
    if (first) {
        if (dp1[i][up][lz][tk][__builtin_popcount(mask)] != -1)
            return dp1[i][up][lz][tk][__builtin_popcount(mask)];
    } else {
        if (dp2[i][up][lz][tk][mask] != -1)
            return dp2[i][up][lz][tk][__builtin_popcount(mask)];
    }
    int ans = 0ll;
    int lim = up ? (s[i] - '0') : 9;
    for (int j = 0; j <= lim; j++) {
        bool nlz = lz && (j == 0), nup = up && (j == lim);
        ans += f(i + 1, nup, nlz, tk + 1, mask | (1 << j), s, first);
        ans += f(i + 1, nup, nlz, tk, mask, s, first);
    }
    if (first)
        return dp1[i][up][lz][tk][__builtin_popcount(mask)] = ans;
    else
        return dp2[i][up][lz][tk][__builtin_popcount(mask)] = ans;
}
void marwan() {
    cin >> l >> r;
    while (l.size() < r.size())
        l = "0" + l;
    n = r.size();
    int j = n - 1;
    while (l.back() == '0')
        j--;
    l[j] = ('0' + (l[j] - '1'));
    j++;
    while (j < n)
        l[j++] = '9';
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    int x = f(0, 1, 1, 0, 0, r, 1);
    int y = f(0, 1, 1, 0, 0, l, 0);
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < 2; b++) {
            for (int c = 0; c < 2; c++) {
                for (int d = 0; d <= n; d++) {
                    for (int e = 0; e <= (1 << 2); e++) {
                        if (dp2[a][b][c][d][e] != -1)
                            cerr << a << " " << d << " " << e << " :::" << dp2[a][b][c][d][e] << endl;
                    }
                    cerr << endl;
                }
            }
        }
    }
    cout << dp1[0][1][1][1][1] << endl;
    int q;
    cin >> q;
    while (q--) {
        cin >> k >> d;
        if (k < d)
            cout << 0 << endl;
        else
            cout << dp1[n][1][1][k][d] - dp2[n][1][1][k][d] << endl;
    }
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