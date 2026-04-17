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
int f(int i, int w, vector<int> &weight, vector<int> &val) {
    if (i < 0) {
        return 3 * w;
    }
    int nimuna = f(i - 1, w, weight, val), nimu = INT_MAX;
    if (weight[i] <= w) {
        nimu = min(nimu,
                   f(i, w - weight[i], weight, val) + val[i]);
    }
    return min(nimu, nimuna);
}
void marwan() {
    vector<int> v(3), t(3), ans(3, INT_MAX), price = {20, 30, 40};
    for (auto &vl : v)
        cin >> vl;
    for (auto &vl : t)
        cin >> vl;
    for (int i = 0; i < 3; i++) {
        int w = v[i];
        ans[i] = f(2, w, price, t);
    }
    cout << accumulate(all(ans), 0ll) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}