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
vector<int> v, immed, dp;
int f(int i) {
  if (i == n)
    return 0;
  if (dp[i] != -1)
    return dp[i];
  int nimuna = f(i + 1), nimu = f(immed[i]) + 1;
  return dp[i] = max(nimuna, nimu);
}
void marwan() {
  cin >> n;
  v.assign(n, 0), immed.assign(n, n), dp.assign(n + 1, 0);
  for (auto &vl : v)
    cin >> vl;
  map<int, int> m;
  for (int i = n - 1; i >= 0; i--) {
    if (m.count(v[i] + 1))
      immed[i] = m[v[i] + 1];
    m[v[i]] = i;
  }
  //   for (auto vl : immed)
  //     cerr << vl << " ";
  //   cerr << endl;
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = dp[immed[i]] + 1;
  }
  int x = 0;
  int mxidx = max_element(all(dp)) - dp.begin();
  cout << dp[mxidx] << endl;
  while (mxidx != n) {
    cout << mxidx + 1 << " ";
    mxidx = immed[mxidx];
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}