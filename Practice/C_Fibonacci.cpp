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
// int A[2][2] = {{1, 1}, {1, 0}}, ide[2][2] = {{1, 0}, {0, 1}};
vector<vector<int>> A = {{1, 1}, {1, 0}};
vector<vector<int>> I = {{1, 0}, {0, 1}};
int mod(int x, int m = M) { return x % m; }
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> c(2, vector<int>(2, 0));
    c[0][0] = mod(mod(a[0][0] * b[0][0]) + mod(a[0][1] * b[1][0]));
    c[0][1] = mod(mod(a[0][0] * b[0][1]) + mod(a[0][1] * b[1][1]));
    c[1][0] = mod(mod(a[1][0] * b[0][0]) + mod(a[1][1] * b[1][0]));
    c[1][1] = mod(mod(a[1][0] * b[0][1]) + mod(a[1][1] * b[1][1]));
    return c;
}
void print(vector<vector<int>> &a) {
    for (auto vl : a) {
        for (auto val : vl)
            cerr << val << " ";
        cerr << endl;
    }
    cerr << endl;
}
vector<vector<int>> binexp(vector<vector<int>> &a, int b) {
    vector<vector<int>> ans = I;
    while (b) {
        if (b & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}
void marwan() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    cout << binexp(A, n - 1)[0][0] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}