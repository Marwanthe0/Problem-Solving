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
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  reverse(all(v));
  int ans = 0, count = 1, sum = accumulate(all(v), 0ll), tsum = 0;
  for (int i = 0; i < n - 1; i++) {
    tsum += v[i], sum -= v[i];
    cerr << tsum << " " << sum << "::";
    ans = max(ans, sum * count + tsum * (n - count));
    // cerr << sum * count + tsum * (n - count) << endl;
    count++;
  }
  cerr << endl;
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