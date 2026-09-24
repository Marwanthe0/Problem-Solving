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
void marwan() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
    }
  }
  auto dp1 = v, dp2 = v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == 0 && j == 0)
        continue;
      dp1[i][j] +=
          max(i ? dp1[i - 1][j] : INT_MIN, j ? dp1[i][j - 1] : INT_MIN);
      dp2[i][j] +=
          min(i ? dp2[i - 1][j] : INT_MAX, j ? dp2[i][j - 1] : INT_MAX);
    }
  }

  if ((n + m - 1) % 2 == 0 && dp1[n - 1][m - 1] >= 0 && dp2[n - 1][m - 1] <= 0)
    yes;
  else
    no;
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