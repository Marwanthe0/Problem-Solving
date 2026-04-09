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

class SGTree {
  public:
    vector<int> seg;
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }
    void build(int idx, int left, int right, vector<int> &v) {
        if (left == right) {
            seg[idx] = v[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * idx + 1, left, mid, v);
        build(2 * idx + 2, mid + 1, right, v);
        seg[idx] = __gcd(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    void update(int idx, int left, int right, int ind, int val) {
        if (left == right) {
            seg[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (ind <= mid)
            update(2 * idx + 1, left, mid, ind, val);
        else
            update(2 * idx + 2, mid + 1, right, ind, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    int query(int idx, int left, int right, int l, int r) {
        if (r < left || l > right)
            return 0;
        else if (left >= l && r >= right) {
            return seg[idx];
        }
        int mid = (left + right) / 2;
        int a = query(2 * idx + 1, left, mid, l, r);
        int b = query(2 * idx + 2, mid + 1, right, l, r);
        return __gcd(a, b);
    }
};
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> dif;
    for (int i = 1; i < n; i++)
        dif.push_back(abs(v[i] - v[i - 1]));
    if (n == 1 || all_of(v.begin(), v.end(), [&](int x) { return x == v[0]; })) {
        while (m--) {
            int l, r;
            cin >> l >> r;
            cout << 0 << endl;
        }
        return;
    }
    SGTree sg(n);
    sg.build(0, 0, n - 2, dif);
    // for (int i = 0; i < sg.seg.size(); i++) {
    //     cout << sg.seg[i] << " ";
    // }
    // cout << endl;
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l == r)
            cout << 0 << endl;
        else
            cout << sg.query(0, 0, n - 2, l - 1, r - 2) << " ";
    }
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