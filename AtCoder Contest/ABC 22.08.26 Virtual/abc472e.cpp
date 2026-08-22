#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int n, m;
vector<vector<int>> g;
vector<int> vis, v;
int cycle, ncycle;
vector<int> path;
bool flag;
void dfs(int nd, int par, int dist) {
  //   cerr << nd << " ";
  vis[nd] = 1;
  v[nd] = dist;
  for (auto child : g[nd]) {
    if (child == par || cycle)
      continue;
    if (vis[child]) {
      if ((v[child] & 1) == ((dist) & 1)) {
        // cerr << child << "::" << nd << "::" << v[child] << "::" << dist <<
        // endl;
        cycle = child;
        ncycle = nd;
        break;
      }
    } else if (!cycle)
      dfs(child, nd, dist + 1);
  }
  //   cerr << nd << " ";
  if (cycle) {
    if (flag)
      path.push_back(nd);
    if (cycle == nd)
      flag = false;
  }
}
void marwan() {
  cin >> n >> m;
  path.clear();
  flag = true;
  g.assign(n + 1, vector<int>());
  vis.assign(n + 1, 0);
  v.assign(n + 1, 0);
  cycle = ncycle = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i] && !cycle) {
      dfs(i, -1, 0);
    }
  }
  if (!cycle) {
    minus;
    return;
  }
  //   cout << cycle << " " << ncycle << endl;
  cout << path.size() << endl;
  for (auto vl : path) {
    cout << vl << " ";
    // if (vl == cycle)
    //   break;
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}