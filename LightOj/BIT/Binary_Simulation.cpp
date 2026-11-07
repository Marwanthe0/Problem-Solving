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
void marwan(int cs) {
    int n;
    string s;
    cin >> s;
    n = s.size();
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(s[i] - '0');
    LazySGTree sg1(n);
    sg1.build(0, 0, n - 1, v);
    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'I') {
            int l, r;
            cin >> l >> r;
            l--, r--;
            sg1.update(0, 0, n - 1, l, r, 1);
        } else {
            int idx;
            cin >> idx;
            idx--;
            int val = sg1.query(0, 0, n - 1, idx, idx);
            cout << (val % 2) << endl;
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