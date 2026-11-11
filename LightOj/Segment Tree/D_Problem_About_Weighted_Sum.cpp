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
    int val, wval;
};
struct lazy_state {
    int add, l;
};
state combine(state a, state b) {
    return {a.val + b.val, a.wval + b.wval}; // sum
}
state identity_state() {
    return {0}; // Edit here
}
lazy_state identity_lazy() {
    return {0, 0}; // edit here
}
void propagate(state &x, lazy_state &g, const lazy_state &f, int len) {
    if (f.add != 0) {
        x.val += f.add * len;
        int r = f.l + len - 1;
        x.wval += f.add * ((f.l + r) * (len) / 2);
        g.add += f.add;
        g.l = f.l;
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
        lazy_state newst = lz[p];
        newst.l = (m + 1);
        apply(p << 1 | 1, m + 1, r, newst);
        lz[p] = identity_lazy();
    }
    void build(vector<state> &base, int p, int l, int r) {
        if (l == r) {
            st[p].val = base[l].val;
            st[p].wval = base[l].wval;
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
            lazy_state newst = f;
            newst.l = l;
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
    vector<state> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i].val;
        v[i].wval = v[i].val * i;
    }
    segment_tree sg1;
    sg1.init(n);
    sg1.build(v);

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, d;
            cin >> l >> r >> d;
            sg1.update(l, r, {d, l});
        } else {
            int l, r;
            cin >> l >> r;
            state ans = sg1.query(l, r);
            int wval = ans.wval, val = ans.val;
            wval -= (val * (l - 1));
            cout << wval << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}