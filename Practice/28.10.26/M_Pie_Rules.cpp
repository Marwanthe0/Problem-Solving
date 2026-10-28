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
vector<int> v;
vector<vector<pair<int, int>>> dp;
pair<int, int> f(int i, bool t) {
  if (i == n)
    return {0, 0};
  if (dp[i][t].first != -1)
    return dp[i][t];

  pair<int, int> ans = {0, 0};
  if (t) {
    // token nijer kache rakhche
    pair<int, int> tans1 = f(i + 1, t);
    tans1.second += v[i];
    // token opponnent ke diche
    pair<int, int> tans2 = f(i + 1, !t);
    tans2.first += v[i];

    if (tans1.first > tans2.first)
      ans = tans1;
    else
      ans = tans2;
  } else {
    // token nijer kache rakhche
    pair<int, int> tans1 = f(i + 1, t);
    tans1.first += v[i];
    // token opponnent ke diche
    pair<int, int> tans2 = f(i + 1, !t);
    tans2.second += v[i];

    if (tans1.second > tans2.second)
      ans = tans1;
    else
      ans = tans2;
  }
  return dp[i][t] = ans;
}
void marwan() {
  cin >> n;
  v.assign(n, 0);
  for (auto &vl : v)
    cin >> vl;
  dp.assign(n + 1, vector<pair<int, int>>(2, {-1, -1}));
  pair<int, int> ans = f(0, 1);
  cout << ans.second << " " << ans.first << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}