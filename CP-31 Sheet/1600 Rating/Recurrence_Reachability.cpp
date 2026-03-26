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
void bin(int a) {
    for (int i = 10; i >= 0; i--)
        cout << ((a >> i) & 1);
    cout << endl;
}
void print(vector<vector<int>> &a) {
    for (auto val : a) {
        for (auto vl : val)
            cout << vl << " ";
        cout << endl;
    }
    cout << endl;
}
vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<vector<int>> ans(a.size(), vector<int>(b[0].size(), 0ll));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++)
                ans[i][j] += a[i][k] * b[k][j];
        }
    }
    return ans;
}
void marwan() {
    // int a, b;
    // cin >> a >> b;
    // bin(a);
    // bin(b);
    // for (int i = 0; i < 10; i++) {
    //     int x = 3 * b - 2 * a;
    //     a = b;
    //     b = x;
    //     bin(b);
    // }
    // cout << endl;
    int n = 10, x, y;
    cin >> x >> y;
    vector<vector<int>> a = {{0, 1}, {-2, 3}}, ans = a, cur = {{x}, {y}};
    print(cur);
    for (int i = 0; i < n; i++) {
        ans = mul(ans, a);
        vector<vector<int>> temp = mul(ans, cur);
        print(temp);
    }
    cout << endl;
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