// 1->1
// 1 1->2
// 1 0 1->3
// 1 1 1 1->4
// 1 0 0 0 1->5
// 1 1 0 0 1 1->6
// 1 0 1 0 1 0 1->7
// 1 1 1 1 1 1 1 1->8
// 1 0 0 0 0 0 0 0 1->9
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
const int lim = 24;
vector<vector<int>> v(lim);
vector<int> f(int n) {
    if (!(n & (n - 1))) {
        return v[(__lg(n))];
    }
    vector<int> x = f(n % (1 << __lg(n)));
    vector<int> tor(all(x));
    while (tor.size() + x.size() < n)
        tor.push_back(0);
    for (auto vl : x)
        tor.push_back(vl);
    return tor;
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> ans = f(n);
    for (auto vl : ans) {
        if (vl)
            cout << k << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < (1 << i); j++) {
            v[i].push_back(1);
        }
    }
    // vector<int> a, b;
    // for (int i = 1; i <= 100; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         if (j == 1 || i == j)
    //             b.push_back(1);
    //         else
    //             b.push_back(a[j - 2] ^ a[j - 1]);
    //     }
    //     for (auto vl : b)
    //         cout << vl << " ";
    //     cout << i;
    //     cout << endl;
    //     a = b;
    //     b.clear();
    // }
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}