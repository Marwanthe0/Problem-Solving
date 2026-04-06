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
vector<int> v;
int f(int l, int r, int k) {
    if ((r - l + 1) < k)
        return 0ll;
    if (l == r) {
        v.push_back(l);
        return l;
    }
    int m = (l + r) / 2;
    if ((r - l + 1) & 1) {
        v.push_back(m);
        return m + (int)f(l, m - 1, k) + (int)f(m + 1, r, k);
    } else {
        return (int)f(l, m, k) + (int)f(m + 1, r, k);
    }
}
void marwan() {
    int n, k;
    cin >> n >> k;
    v.clear();
    // cout << f(1, n, k) << endl;
    // sort(all(v));
    // for (auto vl : v)
    //     cerr << vl << " ";
    // cerr << endl;
    int x = n, y = (x / 2) + (x % 2);
    while (x % 2 == 0) {
        x >>= 1;
        y = (x / 2) + 1;
    }
    // cout << y << endl;
    vector<int> dv;
    for (int i = 1; i * i <= y; i++) {
        if (y % i == 0) {
            dv.push_back(i);
            if (y / i != i)
                dv.push_back(y / i);
        }
    }
    sort(all(dv));
    int target;
    for (auto vl : dv) {
        if (2 * vl - 1 >= k) {
            target = vl;
            break;
        }
    }
    cerr << target << endl;
    if (target == 1) {
        cout << n * 1ll * (n + 1) / 2ll << endl;
        return;
    }
    int sum = 0ll;
    for (int i = target; i <= n; i += target) {
        sum += i;
    }
    cout << sum << endl;
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