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
struct matrix {
    int mat[2][2];
};
matrix i() {
    matrix a;
    a.mat[0][0] = 1;
    a.mat[0][1] = 0;
    a.mat[1][1] = 1;
    a.mat[1][0] = 1;
    return a;
}
matrix mul(matrix a, matrix b) {
    matrix res;
    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 2; j++) {
            int csum = 0;
            for (int k = 0; k < 2; k++) {
                csum += a.mat[i][k] * b.mat[k][j];
            }
            res.mat[i][j] = csum;
        }
    }
    return res;
}
matrix binexp(matrix base, long long e) {
    matrix res = i();
    while (e > 0) {
        if (e & 1)
            res = mul(res, base);
        base = mul(base, base);
        e >>= 1;
    }
    return res;
}

int fib(int n) {
    matrix base, toml;
    toml.mat[0][0] = 1;
    toml.mat[1][0] = 1;
    toml.mat[1][1] = 0;
    toml.mat[0][1] = 1;
    matrix ml = binexp(toml, n + 1);
    return ml.mat[0][1];
}
void marwan() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << fib(i) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}