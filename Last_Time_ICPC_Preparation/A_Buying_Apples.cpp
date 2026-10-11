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
int n, k;
vector<int> w, v;
vector<vector<vector<int>>> dp;
int f(int i, int wt, int packs) {
  if (i == v.size())
    return wt == 0 ? 0 : 1e15;
  if (dp[i][wt][packs] != -1)
    return dp[i][wt][packs];
  int nimuna = f(i + 1, wt, packs), nimu = 1e15;
  if (wt >= w[i] && packs < n)
    nimu = f(i, wt - w[i], packs + 1) + v[i];
  return dp[i][wt][packs] = min(nimu, nimuna);
}
void marwan(int cs) {
  cin >> n >> k;
  v.clear();
  w.clear();
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    if (x != -1) {
      v.push_back(x);
      w.push_back(i);
    }
  }
  dp.assign(v.size() + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, -1)));
  int ans = f(0, k, 0);
  if (ans < 1e15)
    cout << ans << endl;
  else
    minus;
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