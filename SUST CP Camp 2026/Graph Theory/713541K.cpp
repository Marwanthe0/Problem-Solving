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
int n, m, cnt;
vector<int> v, vis;
vector<vector<int>> g, t;
stack<int> st;
void dfs(int nd) {
  vis[nd] = 1;
  for (auto child : g[nd]) {
    if (!vis[child])
      dfs(child);
  }
  st.push(nd);
}
void dfs2(int nd, vector<int> &comps) {
  vis[nd] = 1;
  comps.push_back(nd);
  for (auto child : t[nd]) {
    if (!vis[child]) {
      dfs2(child, comps);
    }
  }
}
void marwan() {
  cin >> n;
  v.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  g.assign(n + 1, vector<int>());
  t.assign(n + 1, vector<int>());
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    t[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  vis.assign(n + 1, 0);
  cnt = 1;
  int ans = 0, ways = 1ll;
  while (!st.empty()) {
    int nd = st.top();
    // cerr << nd << " ";
    st.pop();
    if (!vis[nd]) {
      int mx = LONG_MAX;
      vector<int> comps;
      dfs2(nd, comps);
      //   cout << cnt << endl;
      for (auto vl : comps) {
        mx = min(mx, v[vl]);
      }
      int cnn = 0;
      for (auto vl : comps) {
        if (v[vl] == mx)
          cnn++;
      }
      ans += mx;
      ways = (ways * 1ll * (cnn)) % M;
    }
  }
  cout << ans << " " << ways << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}