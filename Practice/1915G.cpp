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
vector<vector<pair<int, int>>> g;
vector<int> s;
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  s.assign(n + 1, 0ll);
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  vector<vector<int>> dis(n + 1, vector<int>(*max_element(all(s)) + 1, 1e17));
  // state = {cost,node,bike}
  using state = tuple<int, int, int>;
  priority_queue<state, vector<state>, greater<state>> pq;
  dis[1][s[1]] = 0ll;
  pq.push({0, 1, s[1]});
  while (!pq.empty()) {
    auto [d, u, bike] = pq.top();
    pq.pop();
    if (d > dis[u][bike])
      continue;

    for (auto [v, w] : g[u]) {
      int newd = d + bike * 1ll * w;
      int newbike = min(bike, s[v]);
      if (newd < dis[v][newbike]) {
        dis[v][newbike] = newd;
        pq.push({newd, v, newbike});
      }
    }
  }
  int ans = 1e18;
  for (int i = 1; i <= *max_element(all(s)); i++) {
    ans = min(ans, dis[n][i]);
  }
  cout << ans << endl;
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