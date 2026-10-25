#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
struct SGTree {
  vector<int> sgt;
  vector<int> a;
  int n;
  SGTree(int N) {
    this->n = N;
    a.assign(n + 1, 0);
    sgt.assign((n + 1) * 4 + 1, 0);
  }
  int combine(int a, int b) {
    // return a + b;        // -> sum
    // return min(a, b);    // -> min
    return max(a, b); // -> max
  }
  void build(int node, int l, int r) {
    if (l == r) {
      sgt[node] = a[l];
      return;
    }
    int mid = l + (r - l) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
  }
  void update(int node, int l, int r, int idx, int value) {
    if (l == r) {
      sgt[node] = value;
      return;
    }
    int mid = l + (r - l) / 2;
    if (idx <= mid) {
      update(node * 2, l, mid, idx, value);
    } else {
      update(node * 2 + 1, mid + 1, r, idx, value);
    }
    sgt[node] = combine(sgt[2 * node], sgt[2 * node + 1]);
  }
  int query(int node, int l, int r, int ql, int qr) {
    if (l > qr or r < ql) {
      return INT_MIN; // Edit here
    }
    if (l >= ql and r <= qr) {
      return sgt[node];
    }
    int mid = l + (r - l) / 2;
    int left = query(node * 2, l, mid, ql, qr);
    int right = query(node * 2 + 1, mid + 1, r, ql, qr);
    return combine(left, right);
  }
  void build() { build(1, 1, n); }
  void update(int idx, int val) { update(1, 1, n, idx, val); }
  int query(int l, int r) { return query(1, 1, n, l, r); }
};

void marwan() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;

  vector<int> dp(n + 2, 0);
  SGTree sg1(n + 2);
  for (int i = 0; i < n; i++) {
    int vl = a[i] + 1;
    int mx = sg1.query(1, vl - 1);
    dp[vl] = mx + b[i];
    sg1.update(vl, dp[vl]);
  }
  cout << sg1.query(0, n + 1) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}