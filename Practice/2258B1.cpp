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
void marwan() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  vector<int> v(n);
  int ans = n;
  for (auto &vl : v) {
    cin >> vl;
    mp[vl]++;
  }
  sort(all(v));
  for (int i = 1; i <= m; i++) {
    int rem = n - (lower_bound(all(v), i) - v.begin());
    if (mp.count(2 * i))
      rem += mp[2 * i];
    ans = max(ans, rem);
  }
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