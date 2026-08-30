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
int n;
vector<int> c, ans;
vector<vector<int>> g;
map<int, int> dfs(int nd, int p) {
  map<int, int> tans;
  tans[c[nd]]++;
  int mx = 1;
  for (auto child : g[nd]) {
    if (child != p) {
      map<int, int> tmp = dfs(child, nd);
      for (auto [x, y] : tmp) {
        tans[x] += y;
        mx = max(mx, tans[x]);
      }
    }
  }
  //   cerr << nd << "NOde" << mx << endl;
  for (auto [x, y] : tans) {
    if (y == mx)
      ans[nd] += x;
    // cerr << x << " " << y << endl;
  }
  return tans;
}
void marwan() {
  cin >> n;
  c.assign(n + 1, 0);
  ans.assign(n + 1, 0);
  g.assign(n + 1, vector<int>());

  for (int i = 1; i <= n; i++)
    cin >> c[i];
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  map<int, int> mp = dfs(1, -1);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}