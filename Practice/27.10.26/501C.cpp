
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> degree(n), xr(n);
  queue<int> q;
  vector<pair<int, int>> edges;

  for (int i = 0; i < n; i++) {
    cin >> degree[i] >> xr[i];

    if (degree[i] == 1) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    if (degree[v] == 0)
      continue;

    int u = xr[v];

    edges.push_back({v, u});

    degree[v]--;
    degree[u]--;

    xr[u] ^= v;

    if (degree[u] == 1) {
      q.push(u);
    }
  }

  cout << edges.size() << '\n';

  for (auto [u, v] : edges) {
    cout << u << ' ' << v << '\n';
  }

  return 0;
}
