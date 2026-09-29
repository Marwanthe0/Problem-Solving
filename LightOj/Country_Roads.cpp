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
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int n, m;
int target;
vector<vector<pair<int, int>>> g;
vector<int> cost, vis;
void marwan(int cs) {
  cin >> n >> m;
  g.assign(n + 1, vector<pair<int, int>>());
  cost.assign(n + 1, INT_MAX);
  vis.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  cin >> target;
  cost[target] = 0;
  queue<int> q;
  q.push(target);
  vis[target] = 1;
  while (!q.empty()) {
    int nd = q.front();
    q.pop();
    for (auto [child, dist] : g[nd]) {
      if (cost[child] > max(cost[nd], dist)) {
        cost[child] = max(cost[nd], dist);
        q.push(child);
      }
    }
  }
  cout << "Case " << cs << ":" << endl;
  for (int i = 0; i < n; i++)
    if (cost[i] == INT_MAX)
      cout << "Impossible" << endl;
    else
      cout << cost[i] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}