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
long double mod(long double x, long double m = M) {
    if (x > m)
        return x - m;
    return x;
}
int mod(int x, int m = M) { return x % m; }
vector<vector<long double>> A = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}}, ide = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
vector<vector<long double>> mul(vector<vector<long double>> &a, vector<vector<long double>> &b, long double m = M) {
    vector<vector<long double>> c(a.size(), vector<long double>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] = mod(c[i][j] + mod(a[i][k] * b[k][j], m), m);
            }
        }
    }
    return c;
}
vector<vector<long double>> binexp(vector<vector<long double>> &a, int b, long double m = M) {
    vector<vector<long double>> ans = ide;
    while (b) {
        if (b & 1)
            ans = mul(ans, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return ans;
}
int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = mod(ans * a);
        a = mod(a * a);
        b >>= 1;
    }
    return ans;
}
void marwan() {
    int n, a, b, c, k;
    cin >> n >> a >> b >> c >> k;
    long double aa = log(a), bb = log(b), cc = log(c);
    vector<long double> nums = {aa, bb, cc};
    // vector<vector<long double>> x = {{aa}, {bb}, {cc}};
    // A[0][0] = cc, A[0][1] = bb, A[0][2] = aa;
    // A[1][0] = cc, A[2][1] = bb;
    int m1 = M - 1;
    int cpow = mod(mod((mod(n, m1) * mod(n + 1, m1)) - 12) - mod((n - 3) * 6, m1), m1);
    // int tpow = (((n * (n + 1)) - 12) - (n - 3) * 6);
    // cout << cpow << " " << tpow << endl;
    int kk = pow(k, cpow);
    cout << kk << endl;
    vector<vector<long double>> curans = binexp(A, n - 3, log(M));
    curans = mul(curans, x);
    // for (auto vl : curans) {
    //     int idx = 0;
    //     for (auto val : vl) {
    //         cout << exp(val) << ":" << val << " ";
    //         idx++;
    //     }
    //     // cout << mod(mod(exp(val), M) * mod(kk, M), M) << " ";
    //     cout << endl;
    // }
    // cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}