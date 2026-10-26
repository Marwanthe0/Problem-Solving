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
int n, m;
struct Node {
  int idx, count;
  bitset<150> vis;

  Node() {}
  Node(int i, int c, bitset<150> x) : idx(i), count(c), vis(x) {}
  bool operator<(const Node &o) const { return idx < o.idx; }
};
vector<vector<int>> v;
vector<int> uttor;
map<Node, int> dp;
int f(int i, bitset<150> &vis, int count) {
  if (i == m) {
    if (count < n)
      return 0;
    // cout << i << " " << count << ":: ";
    for (int k = 0; k < n; k++) {
      if (vis[k] == 0) {
        // cerr << k << endl;
        return 1;
      }
    }
    return 0;
  }
  if (dp.count(Node(i, vis, count)))
    return dp[{i, {vis, count}}];

  int ans = f(i + 1, vis, count);
  for (int j = 0; j < n; j++) {
    if (v[j][i]) {
      vis[j] = 1;
      ans |= f(i + 1, vis, count + 1);
      vis[j] = 0;
    }
  }
  return dp[Node(i, vis, count)] = ans;
}

void f2(int i, bitset<150> &vis, int count, vector<int> &ans) {
  if (i == m) {
    uttor = ans;
    return;
  }
  int best = dp[{i, {vis, count}}];

  if (dp[{i, {vis, count}}] == best) {
    f2(i + 1, vis, count, ans);
  } else {
    ans.push_back(i + 1);
    f2(i + 1, vis, count, ans);
    ans.pop_back();
  }
}

void marwan() {
  cin >> n >> m;
  v.assign(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  bitset<150> vis;
  int ans = f(0, vis, 0);
  if (!ans) {
    cout << !ans << endl;
  } else {
    vis = bitset<150>();
    vector<int> temp;
    f2(0, vis, 0, temp);
    for (auto vl : uttor)
      cout << vl << " ";
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}