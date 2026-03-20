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
vector<vector<long double>> ans = {{1}, {0}}, A;
vector<vector<long double>> mul(vector<vector<long double>> &a, vector<vector<long double>> &b) {
    vector<vector<long double>> c(a.size(), vector<long double>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    return c;
}
vector<vector<long double>> binexp(vector<vector<long double>> &a, int b) {
    vector<vector<long double>> ans(a.size(), vector<long double>(a[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
        ans[i][i] = 1;
    while (b) {
        if (b & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
void marwan() {
    int n;
    cin >> n;
    long double p, q;
    cin >> p;
    q = 1 - p;
    A = {{q, p}, {p, q}};
    vector<vector<long double>> x = binexp(A, n);
    cout << setprecision(10) << x[0][0] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}