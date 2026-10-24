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
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())

class SGTree {
public:
  vector<int> seg;
  SGTree(int n) { seg.resize(4 * n + 1); }
  void update(int idx, int left, int right, int ind, int val) {
    if (left == right) {
      seg[idx] += val;
      seg[idx] %= M;
      return;
    }
    int mid = (left + right) / 2;
    if (ind <= mid)
      update(2 * idx + 1, left, mid, ind, val);
    else
      update(2 * idx + 2, mid + 1, right, ind, val);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    seg[idx] %= M;
  }
  int query(int idx, int left, int right, int l, int r) {
    if (r < left || l > right)
      return 0;
    else if (l <= left && right <= r) {
      return seg[idx];
    }
    int mid = (left + right) / 2;
    int a = query(2 * idx + 1, left, mid, l, r);
    int b = query(2 * idx + 2, mid + 1, right, l, r);
    return (a + b)%M;
  }
};
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> a = v;
  make_unique(a);
  int m = a.size();
  SGTree sg1(a.size() + 1);
  for (auto vl : v) {
    int pos = lower_bound(all(a), vl) - a.begin() + 1;
    int sum = sg1.query(0, 0, m, 0, pos - 1);
    sg1.update(0, 0, m, pos, sum + 1);
  }
  cout << sg1.query(0, 0, m, 0, a.size());
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}