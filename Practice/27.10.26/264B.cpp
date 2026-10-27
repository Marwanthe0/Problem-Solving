#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 100005
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
vector<vector<int>> divs;
vector<int> vis;
void pre() {
  vis.assign(N + 1, 0);
  divs.assign(N + 1, vector<int>());
  for (int i = 2; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      divs[j].push_back(i);
    }
  }
}
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v) {
    cin >> vl;
    vis[vl]++;
  }
  vector<int> dp(n + 1, 1);
  map<int, int> m;
  int ans = 1;
  for (int i = 0; i < n; i++) {
    for (auto d : divs[v[i]]) {
      if (m.count(d))
        dp[i] = max(dp[i], dp[m[d]] + 1);
    }
    for (auto d : divs[v[i]])
      m[d] = i;
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  marwan();
  return 0;
}