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
int m, n;
string s;
string a, b;
vector<vector<int>> nxt, dp;
bool f(int i, int j) {
  if (i == m) {
    return 0;
  }
  if (j >= n) {
    return true;
  }
  if (dp[i][j] != -1)
    return dp[i][j];
  bool ans = 0;
  for (int k = a[i] - '0'; k <= b[i] - '0'; k++) {
    if (nxt[j][k] == n)
      ans |= true;
    ans |= f(i + 1, nxt[j][k] + 1);
  }
  return dp[i][j] = ans;
}

void marwan(int cs) {
  cin >> s;
  n = s.size();
  cin >> m;
  cin >> a;
  cin >> b;
  vector<int> last(11, n);
  nxt.assign(n + 2, vector<int>(11, n));
  dp.assign(11, vector<int>(n + 6, -1));
  for (int i = n - 1; i >= 0; i--) {
    last[s[i] - '0'] = i;
    for (int j = 0; j <= 9; j++) {
      nxt[i][j] = last[j];
    }
  }
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j < 10; j++)
  //     cout << nxt[i][j] << " ";
  //   cout << endl;
  // }
  int ans = f(0, 0);
  if (ans)
    yes;
  else
    no;
  s.clear();
  dp.clear();
  nxt.clear();
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