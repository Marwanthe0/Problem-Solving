#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
  cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = [",              \
      _print(__VA_ARGS__)
#else
#define dbg(...) ((void)0)
#endif
int n, m;
vector<vector<pair<int, int>>> g;
vector<tuple<int, int, int>> edges;
vector<int> dist;
void marwan() {
  cin >> n >> m;
  g.assign(n + 1, vector<pair<int, int>>());
  dist.assign(n + 1, 1e17);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    c *= -1;
    edges.push_back({a, b, c});
  }
  dist[1] = 0;
  for (int i = 1; i < n; i++) {
    for (auto [u, v, w] : edges) {
      if (dist[u] != 1e17 && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
      }
    }
  }
  vector<int> tdist = dist;
  for (auto [u, v, w] : edges) {
    if (tdist[u] + w < tdist[v]) {
      minus;
      return;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  marwan();
  return 0;
}