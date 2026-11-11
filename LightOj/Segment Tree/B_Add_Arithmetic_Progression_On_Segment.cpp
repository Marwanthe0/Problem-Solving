#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
struct state {
    int val;
};
struct lazy_state {
    int a, d, assignemnt;
    bool pending;
};
state combine(state a, state b) {
    return {a.val + b.val}; // sum
}
state identity_state() {
    return {0}; // Edit here
}
lazy_state identity_lazy() {
    return {0, 0, 0, false}; // edit here
}
void propagate(state &x, lazy_state &child, const lazy_state &p, int len) {
    if (p.pending) {
        x.val = p.assignemnt * len;
        child.assignemnt = p.assignemnt;
        child.pending = true;
        child.a = child.d = 0;
    }
    if (p.a || p.d) {
        int sum = len * p.a + ((len * (len - 1)) / 2) * p.d;
        x.val += sum;
        child.a += p.a, child.d += p.d;
    }
}
struct segment_tree {
    int n;
    vector<state> st;
    vector<lazy_state> lz;

    void init(int _n) {
        n = _n;
        st.assign(4 * n + 4, identity_state());
        lz.assign(4 * n + 4, identity_lazy());
    }
    void apply(int p, int l, int r, const lazy_state &f) {
        propagate(st[p], lz[p], f, r - l + 1);
    }
    void push(int p, int l, int r) {
        int m = (l + r) >> 1;
        apply(p << 1, l, m, lz[p]);
        int newa = lz[p].a + (m + 1 - l) * lz[p].d;
        lazy_state newst = lz[p];
        newst.a = newa;
        apply(p << 1 | 1, m + 1, r, newst);
        lz[p] = identity_lazy();
    }
    void build(vector<state> &base, int p, int l, int r) {
        if (l == r) {
            st[p] = base[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(base, p << 1, l, mid);
        build(base, p << 1 | 1, mid + 1, r);
        st[p] = combine(st[p << 1], st[p << 1 | 1]);
    }
    void update(int p, int l, int r, int ql, int qr, const lazy_state &f) {
        if (qr < l or r < ql)
            return;
        if (ql <= l and r <= qr) {
            int newl = f.a + (l - ql) * f.d;
            lazy_state newst = {newl, f.d, f.assignemnt, f.pending};
            apply(p, l, r, newst);
            return;
        }
        push(p, l, r);
        int m = (l + r) >> 1;
        update(p << 1, l, m, ql, qr, f);
        update(p << 1 | 1, m + 1, r, ql, qr, f);
        st[p] = combine(st[p << 1], st[p << 1 | 1]);
    }
    state query(int p, int l, int r, int ql, int qr) {
        if (qr < l or r < ql)
            return identity_state();
        if (ql <= l and r <= qr)
            return st[p];
        push(p, l, r);
        int mid = (l + r) >> 1;
        state left = query(p << 1, l, mid, ql, qr);
        state right = query(p << 1 | 1, mid + 1, r, ql, qr);
        return combine(left, right);
    }
    void build(vector<state> &base) { build(base, 1, 1, n); }
    void update(int l, int r, const lazy_state &f) { update(1, 1, n, l, r, f); }
    state query(int l, int r) { return query(1, 1, n, l, r); }
};
void marwan() {
    int n, m;
    cin >> n >> m;
    segment_tree sg1;
    sg1.init(n);
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, a, d;
            cin >> l >> r >> a >> d;
            sg1.update(l, r, {a, d, 0, 0});
        } else {
            int idx;
            cin >> idx;
            state val = sg1.query(idx, idx);
            cout << val.val << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}