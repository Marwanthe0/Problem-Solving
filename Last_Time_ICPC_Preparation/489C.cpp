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
int m, sum;
vector<vector<string>> dp;
string mx(int i, int rem) {
  if (i < 0) {
    if (rem == 0)
      return "";
    return "x";
  }
  if (dp[i][rem] != "y")
    return dp[i][rem];
  string tmp = "";
  for (char c = '0'; c <= '9'; c++) {
    if (rem >= c - '0') {
      string tt = mx(i - 1, rem - (c - '0'));
      if (tt[0] == 'x')
        continue;
      tt.push_back(c);
      if (tt > tmp)
        tmp = tt;
    }
  }
  return dp[i][rem] = tmp;
}

string mn(int i, int rem) {
  if (i < 0) {
    if (rem == 0)
      return "";
    return "x";
  }
  if (dp[i][rem] != "y")
    return dp[i][rem];
  string tmp = "";
  for (int j = 0; j <= i + 1; j++)
    tmp.push_back(char('9' + 1));
  bool flag = false;
  for (char c = '0'; c <= '9'; c++) {
    if (i == 0 && c == '0')
      continue;
    if (rem >= c - '0') {
      string tt = mn(i - 1, rem - (c - '0'));
      if (tt[0] == 'x' || tt.size() != i)
        continue;
      tt.push_back(c);
      if (tt < tmp) {
        tmp = tt;
        flag = true;
      }
    }
  }
  if (tmp[0] == char('9' + 1))
    tmp = "";
  return dp[i][rem] = tmp;
}
void marwan() {
  cin >> m >> sum;
  if (m == 1 && sum <= 9) {
    cout << sum << " " << sum << endl;
    return;
  }
  dp.assign(m + 1, vector<string>(sum + 1, "y"));
  string mns = mn(m - 1, sum);
  dp.assign(m + 1, vector<string>(sum + 1, "y"));
  string mxs = mx(m - 1, sum);
  if (mns.size() && mxs.size())
    cout << mns << " " << mxs << endl;
  else
    cout << -1 << " " << -1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}