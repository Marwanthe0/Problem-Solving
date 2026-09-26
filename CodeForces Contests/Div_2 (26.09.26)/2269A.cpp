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
int n, k;
vector<vector<vector<int>>> dp;
int f(int i, int j, int t) {
  if (i == n) {
    if (j == k)
      return 1ll << t;
    else
      return INT_MIN;
  }
  if (dp[i][j][t] != -1)
    return dp[i][j][t];
  return dp[i][j][t] = max(f(i + 1, j, t + 1), f(i + 1, j + 1, 1) + (1ll << t));
}
void marwan() {
  cin >> n >> k;
  int x = max(n, k) + 5;
  dp.assign(x + 1, vector<vector<int>>(x + 1, vector<int>(x + 1, -1)));
  int ans = f(1, 1, 1);
  cout << ans << endl;
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