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
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    void update(int idx, int left, int right, int ind, int val, ) {
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
        return a + b;
    }
};
void marwan() {
    int n1;
    cin >> n1;
    vector<int> a(n1), seg(4 * n1 + 1);
    SGTree sg1(n1);
    sg1.build(0, 0, n1 - 1, a);
    for (auto &vl : a)
        cin >>
            vl;
    int n2;
    cin >> n2;
    vector<int> b(n2);
    for (auto &vl : b)
        cin >> vl;
    SGTree sg2(n2);
    sg2.build(0, 0, n2 - 1, b);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            cout << sg1.query(0, 0, n1 - 1, l1, r1) + sg2.query(0, 0, n2 - 1, l2, r2) << endl;
        } else {
            int arrno, idx, val;
            cin >> arrno >> idx >> val;
            if (arrno == 1) {
                sg1.update(0, 0, n1 - 1, idx, val);
            } else
                sg2.update(0, 0, n2 - 1, idx, val);
        }
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