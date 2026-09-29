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
int n, m, k;
vector<vector<pair<int, int>>> g;
vector<vector<int>> cost;
void marwan() {
  cin >> n >> m >> k;
  g.assign(n + 1, vector<pair<int, int>>());
  // cost[nd][0] = minimum cost to reach there
  cost.assign(n + 1, vector<int>(k, 1e17));
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
  cost[1][0] = 0;
  while (!pq.empty()) {
    auto [ndcost, nd] = pq.top();
    pq.pop();
    if (cost[nd][k - 1] < ndcost)
      continue;
    for (auto [child, childcost] : g[nd]) {
      if (ndcost + childcost < cost[child][k - 1]) {
        cost[child][k - 1] = ndcost + childcost;
        pq.push({cost[child][k - 1], child});
        sort(all(cost[child]));
      }
    }
  }
  //   for (int j = 1; j <= n; j++) {
  for (int i = 0; i < k; i++)
    cout << cost[n][i] << " ";
  // cout << endl;
  //   }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}