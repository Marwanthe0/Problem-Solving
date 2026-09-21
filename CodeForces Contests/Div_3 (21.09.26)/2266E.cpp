#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 200009
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
vector<set<int>> spf;
void pre() {
  spf.assign(N + 1, set<int>());
  spf[1].insert(1);
  for (int i = 2; i <= N; i++) {
    if (spf[i].empty()) {
      spf[i].insert(i);
      for (int j = i; j <= N; j += i) {
        spf[j].insert(i);
      }
    }
  }
  //   for (int i = 1; i <= 20; i++)
  //     cerr << spf[i] << " " << lpf[i] << endl;
}
vector<int> dp;
int f(int x) {
  if (x <= k)
    return dp[x] = 0;
  if (dp[x] != -1)
    return dp[x];
  int ans = 1e18;
  for (auto vl : spf[x]) {
    ans = min(ans, 1 + vl * f(x / vl));
  }
  return dp[x] = ans;
}
void marwan() {
  cin >> n >> k;
  vector<int> v;
  dp.assign(n + 1, -1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x > k) {
      v.push_back(x);
      int val = f(x);
      ans += val;
      //   cerr << x << " " << lpf[x] << " " << val << endl;
    }
  }
  //   cerr << endl;
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}