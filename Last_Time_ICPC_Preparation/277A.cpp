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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  DSU d1(m + 1);
  int ans = 0;
  set<int> lngs;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k == 0)
      ans++;
    v[i].assign(k, 0);
    for (auto &vl : v[i]) {
      cin >> vl;
      lngs.insert(vl);
      d1.unite(v[i][0], vl);
    }
  }
  set<int> st;
  for (auto i : lngs) {
    st.insert(d1.find(i));
  }
  //   cerr << endl;
  cout << ans + max(0ll, (int)st.size() - 1) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}