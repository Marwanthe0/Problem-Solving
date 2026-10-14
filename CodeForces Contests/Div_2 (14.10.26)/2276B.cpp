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
void marwan(int cs) {
  string s;
  cin >> s;
  int ans = 1, n = s.size();
  bool a = 0, b = 0;
  for (int i = 0; i + 2 < n; i++) {
    if (s[i] == s[i + 1] && s[i] == s[i + 2])
      a = 1;
    if (s[i] == s[i + 2] && s[i] != s[i + 1])
      b = 1;
  }
  cout << ans + a + b << endl;
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