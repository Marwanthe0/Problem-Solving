#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
string s;
vector<vector<vector<vector<int>>>> dp;
int f(int i, bool one, bool on, bool zr) {
  if (i >= n)
    return 0;
  if (dp[i][one][on][zr] != -1)
    return dp[i][one][on][zr];
  int ans = 0;
  int val = s[i] - '0';
  if (s[i] == '0' && one) {
    if (on)
      val = 1, ans++;
    else
      ans = INT_MAX, val = 0;
  } else if (s[i] == '1' && one == 0) {
    if (zr)
      val = 0, ans++;
    else
      ans = INT_MAX, val = 1;
  }
  int same = INT_MAX, palta = f(i + 1, 1, on || val, zr || val == 0);
  if (!one)
    same = f(i + 1, 0, on || val, zr || val == 0);
  return dp[i][one][on][zr] = ans + min(same, palta);
}
void marwan() {
  cin >> n;
  cin >> s;
  dp.assign(n + 1, vector<vector<vector<int>>>(
                       2, vector<vector<int>>(2, vector<int>(2, -1))));
  int ans = min(f(0, 0, 0, 0), f(0, 1, 0, 0));
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