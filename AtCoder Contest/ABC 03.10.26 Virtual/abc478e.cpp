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
int n, k;
vector<vector<int>> g, t;
vector<int> vis, ans;
stack<int> st;
void dfs(int nd) {
  vis[nd] = 1;
  for (auto child : g[nd]) {
    if (!vis[child])
      dfs(child);
  }
  st.push(nd);
}
void dfs2(int nd, vector<int> &v) {
  vis[nd] = 1;
  v.push_back(nd);
  for (auto child : t[nd]) {
    if (!vis[child])
      dfs2(child, v);
  }
}
void marwan() {
  cin >> n >> k;
  g.assign(n + 1, vector<int>()), t.assign(n + 1, vector<int>());
  vector<pair<int, int>> norm, strict, ind;
  map<int, int> indeg;
  ans.assign(n + 1, 0);
  for (int i = 0; i < k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    indeg[b]++;
    g[b].push_back(c);
    t[c].push_back(b);
    if (a)
      strict.push_back({b, c});
    // cerr << b << " " << c << endl;
  }
  vis.assign(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    dfs(i);
  }
  vis.assign(n + 1, 0);
  map<int, vector<int>> m;
  int count = 1;
  while (!st.empty()) {
    int nd = st.top();
    // cout << nd << " ";
    if (!vis[nd])
      dfs2(nd, m[count++]);
    st.pop();
  }
  for (auto [x, y] : m) {
    for (auto vl : y) {
      ans[vl] = x;
    }
  }
  for (auto [x, y] : strict) {
    if (ans[x] >= ans[y]) {
      no;
      return;
    }
  }
  for (auto [x, y] : norm) {
    if (ans[x] > ans[y]) {
      no;
      return;
    }
  }
  yes;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}