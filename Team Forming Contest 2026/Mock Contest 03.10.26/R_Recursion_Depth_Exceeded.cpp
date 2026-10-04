#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1"
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int n, k, tcs;
vector<int> a, dp;
vector<pair<int, int>> rng;
// int f(int i) {
//   if (i == n) {
//     return 0;
//   } else if (i > n)
//     return INT_MAX;
//   if (dp[i] != -1)
//     return dp[i];
//   int tinta = INT_MAX, kta = INT_MAX;
//   if (i + 3 <= n && ((v[i + 2] - v[i]) <= 2 * k))
//     tinta = f(i + 3) + 1;
//   if (nxt[i] <= n && ((v[nxt[i] - 1] - v[i]) <= 2 * k))
//     kta = f(nxt[i]) + 1;
//   return dp[i] = min(tinta, kta);
// }

class SGTree {
public:
  vector<int> seg;
  SGTree(int n) { seg.resize(4 * n + 1); }
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
  void update(int idx, int left, int right, int ind, int val) {
    if (left == right) {
      seg[idx] = val;
      return;
    }
    int mid = (left + right) / 2;
    if (ind <= mid)
      update(2 * idx + 1, left, mid, ind, val);
    else
      update(2 * idx + 2, mid + 1, right, ind, val);
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
  }

  int query(int idx, int left, int right, int l, int r) {
    if (r < left || l > right)
      return INT_MAX;
    else if (left >= l && r >= right) {
      return seg[idx];
    }
    int mid = (left + right) / 2;
    int a = query(2 * idx + 1, left, mid, l, r);
    int b = query(2 * idx + 2, mid + 1, right, l, r);
    return min(a, b);
  }
};
void marwan(int cs) {
  cout << "Case " << cs << ": ";
  cin >> n >> k;
  a.assign(n, 0);
  rng.assign(n, {0, 0});
  dp.assign(n + 2, INT_MAX);
  for (auto &vl : a)
    cin >> vl;
  sort(all(a));
  a.push_back(a.back());
  a.push_back(INT_MAX);
  for (int i = 0; i < n; i++) {
    int jaibo = (upper_bound(all(a), a[i] + 2 * k) - a.begin() - 1);
    rng[i].first = min(i + 3, n + 1), rng[i].second = jaibo;
    cerr << a[i] << " " << a[i] + 2 * k << " " << jaibo << " " << i + 3 << " "
         << n + 1 << "::" << rng[i].first << " " << rng[i].second << endl;
  }
  cerr << endl;
  // return;
  for (auto [x, y] : rng)
    cerr << x << " " << y << endl;
  cerr << endl;
  // return;
  dp[n] = 0;
  SGTree sg1(n + 2);
  sg1.build(0, 0, n + 2, dp);
  for (int i = n - 1; i >= 0; i--) {
    if (rng[i].second < rng[i].first)
      continue;
    dp[i] = min(dp[i], sg1.query(0, 0, n + 2, rng[i].first, rng[i].second));
    if (dp[i] != INT_MAX)
      dp[i]++;
    sg1.update(0, 0, n + 2, i, dp[i]);
  }
  for (int i = 0; i < n; i++)
    cout << dp[i] << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tcs;
  for (int i = 1; i <= tcs; i++) {
    marwan(i);
  }
  return 0;
}