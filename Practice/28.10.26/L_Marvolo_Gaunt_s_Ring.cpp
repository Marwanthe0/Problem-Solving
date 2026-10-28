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

int n;
vector<int> v, op;
vector<vector<int>> dp, tdp;
int f(int i, int j) {
  if (j == 3)
    return 0;
  if (i == n)
    return (j == 3 ? 0 : -3e18 + 5);
  if (tdp[i][j])
    return dp[i][j];
  int ans = f(i + 1, j);
  ans = max(ans, v[i] * 1ll * op[j] + f(i, j + 1));
  tdp[i][j] = 1;
  return dp[i][j] = ans;
}
void marwan() {
  op.assign(3, 0);
  cin >> n >> op[0] >> op[1] >> op[2];
  v.assign(n, 0);
  dp.assign(n + 1, vector<int>(4, -1));
  tdp.assign(n + 1, vector<int>(4, 0));
  for (auto &vl : v) {
    cin >> vl;
  }
  cout << f(0, 0) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}