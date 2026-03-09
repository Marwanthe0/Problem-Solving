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
vector<vector<int>> A = {{0, 1}, {3, 2}}, ide = {{1, 0}, {0, 1}};
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> ans = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                ans[i][k] += a[i][j] * b[j][k];
                ans[i][k] %= M;
            }
        }
    }
    return ans;
}
vector<vector<int>> binexp(vector<vector<int>> &a, int b) {
    vector<vector<int>> ans = ide;
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
    vector<vector<int>> ans = binexp(A, n);
    cout << ans[0][0] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}