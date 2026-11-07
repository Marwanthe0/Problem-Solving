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
        return (a + b) % M; // -> sum
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
            sgt[node] = (sgt[node] + value) % M;
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
    void build() { build(0, 0, n); }
    void update(int idx, int val) { update(0, 0, n - 1, idx, val); }
    int query(int l, int r) { return query(0, 0, n - 1, l, r); }
};
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n + 1), a;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        a.push_back(v[i]);
    }
    make_unique(a);
    vector<int> dp(a.size() + 1, 0);

    SGTree sg1(a.size() + 1);
    for (int i = 1; i <= n; i++) {
        int idx = lower_bound(all(a), v[i]) - a.begin() + 1;
        int cnt = sg1.query(0, idx - 1) + 1;
        // cerr << cnt << " ";
        cnt %= M;
        sg1.update(idx, cnt);
    }
    // cerr << endl;
    cout << sg1.query(0, a.size()) % M << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}