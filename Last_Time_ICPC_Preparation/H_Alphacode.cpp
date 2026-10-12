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
int n;
string s;
vector<int> dp;
int f(int i) {
  if (i == n)
    return 1;
  if (dp[i] != -1)
    return dp[i];
  int ekta = 0, duita = 0;
  if (s[i] - '0')
    ekta = f(i + 1);
  if (s[i] == '1' && i + 1 < n)
    duita = f(i + 2);
  else if (s[i] == '2' && i + 1 < n && s[i + 1] >= '0' && s[i + 1] <= '6')
    duita = f(i + 2);
  return dp[i] = ekta + duita;
}
void marwan(string &t) {
  n = t.size();
  s = t;
  dp.assign(n + 1, -1);
  cout << f(0) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1;; i++) {
    string a;
    cin >> a;
    if (a == "0")
      break;
    marwan(a);
  }
  return 0;
}