#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
struct SGTree {
    vector<int> sgt;
    vector<int> a;
    int n;
    SGTree(int n) {
        this->n = n;
        a.assign(n, 0);
        sgt.assign(4 * n, 0);
    }
    int combine(int a, int b) {
        return a + b; // -> sum
        // return min(a, b);    // -> min
        // return max(a, b);    // -> max
    }
    void build(int node, int l, int r) {
        if (l == r) {
            sgt[node] = a[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(node * 2 + 1, l, mid);
        build(node * 2 + 2, mid + 1, r);
        sgt[node] = combine(sgt[2 * node + 1], sgt[2 * node + 2]);
    }
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            sgt[node] = value;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(node * 2 + 1, l, mid, idx, value);
        } else {
            update(node * 2 + 2, mid + 1, r, idx, value);
        }
        sgt[node] = combine(sgt[2 * node + 1], sgt[2 * node + 2]);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (l > qr or r < ql) {
            return 0; // Edit here
        }
        if (l >= ql and r <= qr) {
            return sgt[node];
        }
        int mid = l + (r - l) / 2;
        int left = query(node * 2 + 1, l, mid, ql, qr);
        int right = query(node * 2 + 2, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build() { build(0, 0, n - 1); }
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};
void marwan(int cs) {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    SGTree sg1(n);
    sg1.a = v;
    sg1.build();
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int idx;
            cin >> idx;
            int val = sg1.query(idx, idx);
            sg1.update(idx, 0);
            cout << val << endl;
        } else if (op == 2) {
            int idx, val;
            cin >> idx >> val;
            val += sg1.query(idx, idx);
            sg1.update(idx, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sg1.query(l, r) << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": " << endl;
        marwan(i);
    }
    return 0;
}