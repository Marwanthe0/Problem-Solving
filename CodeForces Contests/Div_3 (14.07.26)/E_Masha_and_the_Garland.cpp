#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())

struct nd {
  public:
    int val, l, r;
    nd(int val = 0, int l = -1, int r = -1) {
        this->val = val;
        this->l = l;
        this->r = r;
    }
};
class SGTree {
  public:
    vector<nd> seg;
    SGTree(int n) {
        seg.resize(4 * n + 1);
    }
    void build(int idx, int left, int right, vector<int> &v) {
        if (left == right) {
            seg[idx] = nd(0, v[left], v[left]);
            return;
        }
        int mid = (left + right) / 2;
        build(2 * idx + 1, left, mid, v);
        build(2 * idx + 2, mid + 1, right, v);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    nd merge(nd a, nd b) {
        if (a.l == -1)
            return b;
        if (b.l == -1)
            return a;
        int count = a.val + b.val;
        if (a.r == b.l) {
            count += 1;
        }
        return nd(count, a.l, b.r);
    }
    // void update(int idx, int left, int right, int ind, int val, ) {
    //     if (left == right) {
    //         seg[idx] = val;
    //         return;
    //     }
    //     int mid = (left + right) / 2;
    //     if (ind <= mid)
    //         update(2 * idx + 1, left, mid, ind, val);
    //     else
    //         update(2 * idx + 2, mid + 1, right, ind, val);
    //     seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    // }
    nd query(int idx, int left, int right, int l, int r) {
        if (r < left || l > right)
            return nd(0, -1, -1);
        if (left >= l && r >= right)
            return seg[idx];

        int mid = (left + right) / 2;
        nd a = query(2 * idx + 1, left, mid, l, r);
        nd b = query(2 * idx + 2, mid + 1, right, l, r);
        return merge(a, b);
    }
};
void marwan() {
    int n, k;
    cin >> n >> k;
    SGTree sg1(n);
    string s;
    cin >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = s[i] - '0';
    sg1.build(0, 0, n - 1, v);
    while (k--) {
        int l, r, op;
        cin >> l >> r >> op;
        l--, r--;
        // cout << sg1.query(0, 0, n - 1, l, r).val << endl;
        if ((sg1.query(0, 0, n - 1, l, r).val + 1) / 2 <= op)
            yes;
        else
            no;
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