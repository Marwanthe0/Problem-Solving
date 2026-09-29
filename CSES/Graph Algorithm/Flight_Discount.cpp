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
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<pair<int, int>>());
  cost.assign(n + 1, vector<int>(2, 1e17));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
  }
  // gota = cost, node, operation
  using gota = tuple<int, int, int>;
  priority_queue<gota, vector<gota>, greater<gota>> pq;
  pq.push({0, 1, 0});
  cost[1][0] = cost[1][1] = 0;
  while (!pq.empty()) {
    auto [ndcost, nd, op] = pq.top();
    pq.pop();
    if (ndcost > cost[nd][op])
      continue;
    for (auto [child, childcost] : g[nd]) {
      if (childcost + ndcost < cost[child][op]) {
        cost[child][op] = childcost + ndcost;
        pq.push({cost[child][op], child, op});
      }
      if (!op && ndcost + (childcost / 2) < cost[child][1]) {
        cost[child][1] = ndcost + (childcost / 2);
        pq.push({cost[child][1], child, 1});
      }
      // if (op == 0) {
      //   int newcost = ndcost + childcost, newcost1 = ndcost + childcost / 2;
      //   if (newcost < cost[child][0]) {
      //     cost[child][0] = newcost;
      //     pq.push({cost[child][0], child, 0});
      //   }
      //   if (newcost1 < cost[child][1]) {
      //     cost[child][1] = newcost1;
      //     pq.push({cost[child][1], child, 1});
      //   }
      // } else {
      //   int newcost1 = ndcost + childcost;
      //   if (newcost1 < cost[child][1]) {
      //     cost[child][1] = newcost1;
      //     pq.push({cost[child][1], child, 1});
      //   }
      // }
    }
  }
  cout << cost[n][1] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}