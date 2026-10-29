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
      if (sz[a] < sz[b])
        swap(a, b);
      p[b] = a;
      sz[a] += sz[b];
    }
  }
};

void marwan() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  DSU ds(n);
  for (int i = 0; i < k; i++) {
    for (int j = i; j < n; j += k) {
      ds.unite(j, i);
      ds.unite(n - j - 1, i);
    }
  }
  vector<map<char, int>> final(n);
  for (int i = 0; i < n; i++) {
    // cout << ds.find(i) << " ";
    final[ds.find(i)][s[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (final[i].empty())
      continue;
    int mx = 0, sum = 0;
    for (auto [x, y] : final[i]) {
      mx = max(mx, y);
      sum += y;
    }
    ans += (sum - mx);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    marwan();
  return 0;
}