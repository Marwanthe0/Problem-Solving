#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
int n;
vector<int> v;
vector<vector<vector<int>>> dp;
int f(int i, int mex, int mx) {
  if (i >= n)
    return (int)(abs(mx - mex) <= 1);
  if (dp[i][mex][mx] != -1)
    return dp[i][mex][mx];
  int nimu = f(i + 1, ((v[i] == mex) ? mex + 1 : mex), max(mx, v[i])) % M,
      nimuna = f(i + 1, mex, mx) % M;
  return dp[i][mex][mx] = (nimu + nimuna) % M;
}
void marwan() {
  cin >> n;
  v.assign(n, 0);
  dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  int ans = (f(0, 0, 0) - 1 + M) % M;
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