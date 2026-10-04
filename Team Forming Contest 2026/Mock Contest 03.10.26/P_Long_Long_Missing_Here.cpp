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
// let right = 0, down = 1;
// combination = 00,01,10,11 = right|right, right|down, down|right, down|down
int n, m;
vector<vector<int>> v;
vector<vector<vector<int32_t>>> dp;
int f(int step, int r1, int r2) {
  int c1 = step - r1, c2 = step - r2;
  if (r1 == n && r2 == n && c1 == m && c2 == m)
    return v[r1][c1];
  if (dp[step][r1][r2] != -1)
    return dp[step][r1][r2];
  if ((step > 2 && r1 == r2 && c1 == c2) ||
      (r1 > n || r2 > n || c1 > m || c2 > m))
    return INT_MIN;
  int rightright = f(step + 1, r1, r2);
  int rightdown = f(step + 1, r1, r2 + 1);
  int downright = f(step + 1, r1 + 1, r2);
  int downdown = f(step + 1, r1 + 1, r2 + 1);
  return dp[step][r1][r2] = max({rightright, rightdown, downdown, downright}) +
                            v[r1][c1] + ((r2 == 1 && c2 == 1) ? 0 : v[r2][c2]);
}
void marwan(int cs) {
  cout << "Case " << cs << ": ";
  cin >> n >> m;
  dp.assign(n + m + 5,
            vector<vector<int32_t>>(n + 5, vector<int32_t>(n + 5, -1)));
  v.assign(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      cin >> v[i][j];
  }
  int ans = f(2, 1, 1);
  cout << ans << endl;
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