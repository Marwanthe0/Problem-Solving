#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 999999937
#define MM 1000000009
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
int n, m, start, dest;
vector<int> ds, de, wss, we, wss2, we2;
vector<vector<pair<int, int>>> g, t;
vector<array<int, 3>> edges;
void dijkstra(int src, vector<int> &dist, vector<int> &ways, vector<int> &ways2,
              vector<vector<pair<int, int>>> &g) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, src});
  dist[src] = 0;
  ways[src] = 1;
  ways2[src] = 1;
  while (!pq.empty()) {
    auto [ndcost, nd] = pq.top();
    pq.pop();
    if (ndcost > dist[nd])
      continue;
    for (auto [child, childcost] : g[nd]) {
      if (childcost + ndcost < dist[child]) {
        ways[child] = ways[nd];
        ways2[child] = ways2[nd];
        dist[child] = childcost + ndcost;
        pq.push({dist[child], child});
      } else if (childcost + ndcost == dist[child]) {
        ways[child] = ((ways[child] % MM) + (ways[nd] % MM)) % MM;
        ways2[child] = (ways2[child] + ways2[nd]) % M;
      }
    }
  }
}
void marwan() {
  cin >> n >> m >> start >> dest;
  g.assign(n + 1, vector<pair<int, int>>());
  t.assign(n + 1, vector<pair<int, int>>());
  ds.assign(n + 1, INF);
  de.assign(n + 1, INF);
  wss.assign(n + 1, 0);
  we.assign(n + 1, 0);
  wss2.assign(n + 1, 0);
  we2.assign(n + 1, 0);
  edges.clear();
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    t[b].push_back({a, c});
    edges.push_back({a, b, c});
  }
  dijkstra(start, ds, wss, wss2, g);
  dijkstra(dest, de, we, we2, t);
  int ans = ds[dest];
  //   for (int i = 1; i <= n; i++) {
  //     cerr << ds[i] << " " << wss[i] << endl;
  //   }
  //   cerr << endl;
  //   for (int i = 1; i <= n; i++) {
  //     cerr << de[i] << " " << we[i] << endl;
  //   }
  //   cerr << endl;
  for (auto [u, v, cost] : edges) {
    if (((wss[u] % MM) * 1ll * (we[v] % MM)) % MM == wss[dest] % MM &&
        ((wss2[u] % M) * 1ll * (we2[v] % M) % M == wss2[dest] % M) &&
        ds[u] + cost + de[v] == ans)
      yes;
    else {
      int x = cost - (ans - (ds[u] + de[v]) - 1);
      if (x >= cost)
        no;
      else
        cout << "CAN " << x << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}