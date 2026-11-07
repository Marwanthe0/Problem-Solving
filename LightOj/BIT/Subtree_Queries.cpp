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
int n, q;
vector<int> a, in, out, flat;
vector<vector<int>> g;
int timer = 0;
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
void dfs(int u, int p = -1) {
    flat[timer] = u;
    in[u] = timer++;

    for (auto v : g[u]) {
        if (v != p)
            dfs(v, u);
    }
    out[u] = timer;
}
void marwan() {
    cin >> n >> q;
    a.assign(n, 0);
    in.assign(n + 1, 0);
    out.assign(n + 1, 0);
    flat.assign(n, 0);
    for (auto &vl : a)
        cin >> vl;
    g.assign(n + 1, vector<int>());
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for (int i = 0; i < n; i++) {
        flat[i] = a[flat[i] - 1];
    }
    SGTree sg1(n);
    sg1.a = flat;
    sg1.build();
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, nu;
            cin >> u >> nu;
            sg1.update(in[u], nu);
        } else {
            int u;
            cin >> u;
            int l = in[u], r = out[u] - 1;
            cout << sg1.query(l, r) << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    marwan();
    return 0;
}