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
int mod(int x, int m = M) { return x % m; }
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                c[i][j] = mod(c[i][j] + mod(a[i][k] * b[k][j]));
            }
        }
    }
    return c;
}
vector<vector<int>> binexp(vector<vector<int>> &a, int b) {
    vector<vector<int>> ans(a.size(), vector<int>(a[0].size(), 0));
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u][v]++;
    }
    cout << binexp(a, k)[0][n - 1] << endl;
    // vector<vector<int>> ans = binexp(a, k);
    // for (auto vl : ans) {
    //     for (auto val : vl)
    //         cout << val << " ";
    //     cout << endl;
    // }
    // cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}