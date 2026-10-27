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
vector<int> vis(N + 1, 0), dp(N + 1, 1);
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v) {
    cin >> vl;
    vis[vl]++;
  }
  int mx = v.back();
  for (auto vl : v) {
    for (int j = 2 * vl; j <= mx; j += vl) {
      if (vis[j]) {
        dp[j] = max(dp[j], dp[vl] + 1);
      }
    }
  }
  int ans = 0;
  for (auto vl : v) {
    ans = max(ans, dp[vl]);
    dp[vl] = 1;
    vis[vl] = 0;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}