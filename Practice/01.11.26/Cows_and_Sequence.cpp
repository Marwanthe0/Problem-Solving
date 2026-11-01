#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
class LazySGTree {
  public:
    vector<int> seg, lazy;
    LazySGTree(int n) {
        seg.resize(4 * n + 1, 0);
        lazy.resize(4 * n + 1, 0);
    }
    void build(int idx, int left, int right, vector<int> &v) {
        if (left == right) {
            seg[idx] = v[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * idx + 1, left, mid, v);
        build(2 * idx + 2, mid + 1, right, v);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    void update(int idx, int left, int right, int l, int r, int val) {
        if (lazy[idx] != 0) {
            seg[idx] += (right - left + 1) * lazy[idx];
            if (left != right) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (r < left || l > right)
            return;
        if (left >= l && r >= right) {
            seg[idx] += (right - left + 1) * val;
            if (left != right) {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }
        int mid = (left + right) / 2;
        update(2 * idx + 1, left, mid, l, r, val);
        update(2 * idx + 2, mid + 1, right, l, r, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    int query(int idx, int left, int right, int l, int r) {
        if (lazy[idx] != 0) {
            seg[idx] += (right - left + 1) * lazy[idx];
            if (left != right) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (r < left || l > right)
            return 0;
        if (left >= l && r >= right)
            return seg[idx];
        int mid = (left + right) / 2;
        int a = query(2 * idx + 1, left, mid, l, r);
        int b = query(2 * idx + 2, mid + 1, right, l, r);
        return a + b;
    }
};
void marwan() {
    int n;
    cin >> n;
    n += 5;
    vector<int> v(n, 0);
    LazySGTree sg1(n);
    sg1.build(0, 0, n - 1, v);
    int sz = 1;
    for (int i = 0; i < n - 5; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, x;
            cin >> a >> x;
            sg1.update(0, 0, n - 1, 0, a - 1, x);
            cout << fixed << setprecision(6) << (long double)sg1.query(0, 0, n - 1, 0, n - 1) / sz << endl;
        } else if (op == 2) {
            int x;
            cin >> x;
            sg1.update(0, 0, n - 1, sz, sz, x);
            sz++;
            cout << fixed << setprecision(6) << (long double)sg1.query(0, 0, n - 1, 0, n - 1) / sz << endl;
        } else {
            if (sz > 1) {
                sz--;
                int val = sg1.query(0, 0, n - 1, sz, sz);
                sg1.update(0, 0, n - 1, sz, sz, -val);
                cout << fixed << setprecision(6) << (long double)sg1.query(0, 0, n - 1, 0, n - 1) / sz << endl;
            }
        }
        // cerr << sz << endl;
        // for (int i = 0; i < n; i++)
        //     cerr << sg1.query(0, 0, n - 1, i, i) << " ";
        // cerr << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}