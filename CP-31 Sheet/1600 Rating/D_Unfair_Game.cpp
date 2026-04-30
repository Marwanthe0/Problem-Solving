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
vector<vector<int>> nCr(32, vector<int>(32, -1));
int f(int n, int r) {
    if (n == 0 || r == 0)
        return 1;
    if (nCr[n][r] != -1)
        return nCr[n][r];
    return nCr[n][r] = f(n - 1, r - 1) + f(n - 1, r);
}
void pre() {
    for (int i = 0; i <= 31; i++) {
        for (int j = 0; j <= 31; j++) {
            nCr[i][j] = f(i, j);
        }
    }
}
void marwan() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    // for (int i = 1; i <= n; i++) {
    //     int lg = __lg(i);
    //     for (int j = 5; j >= 0; j--)
    //         cout << (1 & (i >> j));
    //     cout << endl;
    //     cout << lg << " " << __builtin_popcount(i) << endl;
    // }
    // cout << endl;
    int tk = k;
    count = 0;
    for (int i = 1; (1 << i) <= n; i++) {
        int l = i;
        int high = 2 * l - 1;
        // cerr << l << " " << high << endl;
        int r = l - 1;
        int c = k - l;
        if (c >= r){
            count += nCr[c][r];
            cerr << c << " " << r << endl;
        }
    }
    cerr << endl;
    if (__lg(n) + __builtin_popcount(n) > tk)
        count++;
    cout << count << endl;
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