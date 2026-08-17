#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
vector<vector<int>> g;
vector<bool> spec;
vector<int> ans;

bool dfs(int nd) {
  vector<int> childs;
  for (int child : g[nd]) {
    if (dfs(child)) {
      //   cerr << child << endl;
      childs.push_back(child);
    }
  }
  if (spec[nd]) {
    for (int child : childs) {
      ans.push_back(child);
    }
    return true;
  } else {
    if (childs.empty()) {
      return false;
    }
    for (int i = 1; i < childs.size(); i++) {
      ans.push_back(childs[i]);
    }
    return true;
  }
}
void marwan() {
  cin >> n;
  g.assign(n + 1, vector<int>());
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    g[x].push_back(i);
  }
  cin >> m;
  spec.assign(n + 1, false);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    spec[x] = 1;
  }

  dfs(1);

  cout << ans.size();
  for (int vl : ans) {
    cout << " " << vl;
  }
  cout << endl;
  ans.clear();
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