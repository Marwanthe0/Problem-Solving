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
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> m;
  for (auto &vl : v) {
    cin >> vl;
    m[vl]++;
  }
  int ans = 0, flag = 0;
  for (auto [vl, frq] : m) {
    if (frq >= 2)
      ans++;
    else
      flag = 1;
  }
  cout << max(ans + flag, ((int)m.size() + 1) / 2) << endl;
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