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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    while (k--) {
        int l, r;
        cin >> l >> r;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}