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
vector<vector<int>> g;
vector<int> vis;
bool flag;
void dfs(int nd, vector<int> &tmp) {
  vis[nd] = 1;
  for (auto child : g[nd]) {
    if (vis[child] == 1) {
      flag = true;
    } else if (vis[child] == 0)
      dfs(child, tmp);
    if (flag)
      return;
  }
  vis[nd] = 2;
}
void marwan(int cs) {
  int n;
  cin >> n;
  g.assign(2 * n + 1, vector<int>());
  vis.assign(2 * n + 1, 0);
  map<string, int> m;
  flag = false;
  int count = 0;
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    if (!m.count(a))
      m[a] = ++count;
    if (!m.count(b))
      m[b] = ++count;
    int x = m[a], y = m[b];
    g[x].push_back(y);
  }
  //   for (int i = 1; i <= count; i++) {
  //     cout << i << ">>";
  //     for (auto vl : g[i])
  //       cout << vl << " ";
  //     cout << endl;
  //   }
  //   cout << endl;
  //   cout << endl;
  //   return;
  for (int i = 1; i <= count; i++) {
    vector<int> tmp;
    if (!vis[i])
      dfs(i, tmp);
    if (flag)
      break;
  }
  cout << "Case " << cs << ": " << (flag ? "No" : "Yes") << endl;
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