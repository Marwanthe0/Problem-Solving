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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &vl : v) {
    cin >> vl;
    vl %= k;
  }
  int sum = 0;
  int l = 0, r = 0;
  map<int, int> m;
  m[0]++;
  int ans = 0, sum2 = 0;
  while (r < n) {
    sum += v[r];
    // sum %= k;
    if (r - l + 1 > k) {
      ans += m[sum % k];
      sum2 += v[l++];
      //   sum2 %= k;
      m[sum2 % k]++;
    }
    r++;
  }
  cout << ans << endl;
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