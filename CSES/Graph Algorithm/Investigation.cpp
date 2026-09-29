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
int n, m;
vector<vector<pair<int, int>>> g;
vector<vector<int>> cost;
vector<int> ways;
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<pair<int, int>>());
  // cost[nd][0] = minimum cost to reach there
  // cost[nd][1] = minimum flight to reach that cost
  // cost[nd][2] = maximum flight to reach that cost
  cost.assign(n + 1, vector<int>(3, 1e17));
  for (int i = 1; i <= n; i++)
    cost[i][2] = 0;
  ways.assign(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  // gota = cost, node, minimum flight,maximum flight
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, 1});
  ways[1] = 1;
  cost[1][0] = cost[1][1] = cost[1][2] = 0;
  while (!pq.empty()) {
    auto [ndcost, nd] = pq.top();
    pq.pop();
    if (ndcost > cost[nd][0])
      continue;
    for (auto [child, childcost] : g[nd]) {
      if (ndcost + childcost < cost[child][0]) {
        ways[child] = ways[nd];
        cost[child][0] = ndcost + childcost;
        cost[child][1] = cost[nd][1] + 1;
        cost[child][2] = cost[nd][2] + 1;
        pq.push({cost[child][0], child});
      } else if (ndcost + childcost == cost[child][0]) {
        ways[child] = (ways[child] + ways[nd]) % M;
        cost[child][1] = min(cost[child][1], cost[nd][1] + 1);
        cost[child][2] = max(cost[child][2], cost[nd][2] + 1);
      }
    }
  }
  cout << cost[n][0] << " " << ways[n] << " " << cost[n][1] << " " << cost[n][2]
       << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}