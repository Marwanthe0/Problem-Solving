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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
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
class LazySGTree {
public:
  vector<int> seg, lazy;
  LazySGTree(int n) {
    seg.resize(4 * n + 1, 0ll);
    lazy.resize(4 * n + 1, 0ll);
  }
  void build(int idx, int left, int right, vector<int> &v) {
    if (left == right) {
      seg[idx] = v[left];
      return;
    }
    int mid = (left + right) / 2;
    build(2 * idx + 1, left, mid, v);
    build(2 * idx + 2, mid + 1, right, v);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
  }
  void update(int idx, int left, int right, int l, int r, int val) {
    if (lazy[idx] != 0) {
      seg[idx] += lazy[idx];
      if (left != right) {
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
      }
      lazy[idx] = 0ll;
    }
    if (r < left || l > right)
      return;
    if (left >= l && right <= r) {
      seg[idx] += val;
      if (left != right) {
        lazy[2 * idx + 1] += val;
        lazy[2 * idx + 2] += val;
      }
      return;
    }
    int mid = (left + right) / 2;
    update(2 * idx + 1, left, mid, l, r, val);
    update(2 * idx + 2, mid + 1, right, l, r, val);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
  }
  int query(int idx, int left, int right, int l, int r) {
    if (lazy[idx] != 0) {
      seg[idx] += lazy[idx];
      if (left != right) {
        lazy[2 * idx + 1] += lazy[idx];
        lazy[2 * idx + 2] += lazy[idx];
      }
      lazy[idx] = 0ll;
    }
    if (r < left || l > right)
      return INF;
    if (left >= l && right <= r)
      return seg[idx];
    int mid = (left + right) / 2;
    int a = query(2 * idx + 1, left, mid, l, r);
    int b = query(2 * idx + 2, mid + 1, right, l, r);
    return min(a, b);
  }
};
void marwan() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> pf(n, 0ll);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A')
      pf[i] = 1;
    else
      pf[i] = -1;
    if (i)
      pf[i] += pf[i - 1];
  }
  LazySGTree sgt(n);
  sgt.build(0, 0, n - 1, pf);
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      pos--;
      if (c != s[pos]) {
        if (c == 'A') {
          sgt.update(0, 0, n - 1, pos, n - 1, 2);
        } else {
          sgt.update(0, 0, n - 1, pos, n - 1, -2);
        }
        s[pos] = c;
      }
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int val = sgt.query(0, 0, n - 1, l, r),
          val2 = l - 1 >= 0 ? sgt.query(0, 0, n - 1, l - 1, l - 1) : 0ll;
      if (val >= val2)
        yes;
      else
        no;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}