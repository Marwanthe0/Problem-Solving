#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
string s;
int n;
vector<vector<int>> dp;
int f(int i, int j) {
  if (i > j)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int ans = INT_MAX;
  if (s[i] == s[j])
    ans = min(ans, f(i + 1, j - 1));
  ans = min({ans, 1 + f(i + 1, j), 1 + f(i, j - 1), 1 + f(i + 1, j - 1)});
  return dp[i][j] = ans;
}
void marwan(int cs) {
  cin >> s;
  dp.assign(s.size() + 1, vector<int>(s.size() + 1, -1));
  cout << f(0, s.size() - 1) << endl;
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