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
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> dp(n, 1), parent(n, -1);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    if (m.count(v[i] - 1)) {
      dp[i] = max(dp[i], dp[m[v[i] - 1]] + 1);
      parent[i] = m[v[i] - 1];
    }
    m[v[i]] = i;
  }
  cout << *max_element(all(dp)) << endl;
  vector<int> ans;
  int pos = max_element(all(dp)) - dp.begin();
  while (pos != -1) {
    ans.push_back(pos + 1);
    pos = parent[pos];
  }
  reverse(all(ans));
  for (auto vl : ans)
    cout << vl << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}