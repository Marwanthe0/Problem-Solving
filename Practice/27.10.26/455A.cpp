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
map<int, int> m;
vector<int> v, dp;
int n;
int f(int i) {
  if (i >= n) {
    return 0;
  }
  if (dp[i] != -1)
    return dp[i];
  int ans = f(i + 1);
  if (i + 1 < n && v[i + 1] == v[i] + 1) {
    ans = max(ans, f(i + 2) + v[i] * m[v[i]]);
  } else {
    ans = max(ans, f(i + 1) + v[i] * m[v[i]]);
  }
  return dp[i] = ans;
}
void marwan() {
  cin >> n;
  v.assign(n, 0);
  dp.assign(n, -1);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    m[v[i]]++;
  }
  make_unique(v);
  n = v.size();
  cout << f(0) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}