#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
int n, k;
vector<int> v;
vector<vector<int8_t>> dp;
int f(int i, int rem) {
  if (i == n)
    return 0;
  if (dp[i][rem] != -1)
    return dp[i][rem];
  int nimuna = f(i + 1, rem), nimu = 0;
  if (rem >= (i + 1) * v[i])
    nimu = f(i + 1, rem - (i + 1) * v[i]) + 1;
  return dp[i][rem] = max(nimu, nimuna);
}
void marwan() {
  cin >> n >> k;
  v.assign(n, 0);
  dp.assign(n + 1, vector<int8_t>(k + 1, -1));
  for (auto &vl : v)
    cin >> vl;
  reverse(all(v));
  int ans = f(0, k);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  marwan();
  return 0;
}