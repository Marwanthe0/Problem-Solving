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
int n, q;
vector<vector<int>> g;
vector<int> red, dist;
void dfs(int nd, int p, int d) {
  if (dist[nd] < d)
    return;
  else
    dist[nd] = d;
  //   cerr << nd << endl;
  for (auto child : g[nd]) {
    if (child != p) {
      dfs(child, nd, d + 1);
    }
  }
}
void marwan() {
  cin >> n >> q;
  g.assign(n + 1, vector<int>());
  red.assign(n + 1, 0);
  dist.assign(n + 1, INT_MAX);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  red[1] = 1;
  dist[1] = 0;
  dfs(1, -1, 0);
  //   return;
  //   for (int i = 1; i <= n; i++)
  //     cerr << dist[i] << " ";
  while (q--) {
    int op, nd;
    cin >> op >> nd;
    if (op == 1) {
      red[nd] = 1;
      dist[nd] = 0;
      dfs(nd, -1, 0);
    } else {
      cout << dist[nd] << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}