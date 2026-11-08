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
struct state {
    int val[3];
    state(int a, int b, int c) {
        val[0] = a, val[1] = b, val[2] = c;
    }
};
struct lazy_state {
    int add, assignemnt;
    bool pending;
};
state combine(state a, state b) {
    for (int i = 0; i < 3; i++) {
        a.val[i] += b.val[i];
    }
    return a;
}
state identity_state() {
    return state(0, 0, 0); // Edit here
}
lazy_state identity_lazy() {
    return {0, 0, false}; // edit here
}
void propagate(state &x, lazy_state &g, const lazy_state &f, int len) {
    if (f.add != 0) {
        state temp = x;
        for (int i = 0; i < 3; i++) {
            x.val[(i + f.add) % 3] = temp.val[i];
        }
        g.add = (g.add + f.add) % 3;
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
        apply(p << 1 | 1, m + 1, r, lz[p]);
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
            apply(p, l, r, f);
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
void marwan(int cs) {
    int n, q;
    cin >> n >> q;
    segment_tree sg1;
    sg1.init(n);
    vector<state> v(n + 1, state(1, 0, 0));
    sg1.build(v);
    while (q--) {
        int op;
        cin >> op;
        if (op == 0) {
            int l, r;
            cin >> l >> r;
            l++, r++;
            sg1.update(l, r, {1, 0, false});
        } else {
            int l, r;
            cin >> l >> r;
            l++, r++;
            state st = sg1.query(l, r);
            cout << st.val[0] << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}