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
struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n + 1), sz(n + 1, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      if (a < b)
        swap(a, b);
      p[b] = a;
    }
  }
};

void marwan() {
  int n, m;
  cin >> n >> m;
  vector<int> ans(n + 1, 0);
  DSU ds(n + 1);
  for (int i = 0; i < m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    int cnt = 0;

    while (l <= r) {
      l = ds.find(l);
      if (l > r)
        break;
      if (l != x) {
        ans[l] = x;
        ds.unite(l, l + 1);
      } else
        l++;
      if (cnt >= 5)
        break;
    }
  }
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}