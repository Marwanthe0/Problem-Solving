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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
vector<vector<int>> g;
vector<int> vis;
void dfs(int nd, vector<int> &path) {
  vis[nd] = 1;
  path.push_back(nd);
  for (auto child : g[nd]) {
    if (!vis[child])
      dfs(child, path);
  }
}
void marwan() {
  int n;
  cin >> n;
  map<int, map<int, int>> m;
  g.assign(n + 1, vector<int>());
  vis.assign(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    m[a][b] = c;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int ans1 = 0, ans2 = 0;
  vector<int> ord = {0};
  dfs(1, ord);
  //   for (auto vl : ord)
  //     cerr << vl << " ";
  //   cerr << endl;
  for (int ii = 1, jj = n; ii < n; ii++, jj--) {
    int i = ord[ii], j = ord[jj], ip1 = ord[ii + 1], jm1 = ord[jj - 1];
    if (m.count(i) && m[i].count(ip1)) {
    } else {
      ans1 += m[ip1][i];
    }
    if (m.count(j) && m[j].count(jm1)) {

    } else {
      ans2 += m[jm1][j];
    }
  }
  if (m.count(ord[n]) && m[ord[n]].count(ord[1])) {
  } else
    ans1 += m[ord[1]][ord[n]];

  if (m.count(ord[1]) && m[ord[n]].count(ord[n])) {
  } else
    ans2 += m[ord[n]][ord[1]];
  cerr << ans1 << " " << ans2 << endl;
  cout << min(ans1, ans2) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}