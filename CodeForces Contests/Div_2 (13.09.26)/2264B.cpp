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
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  if (m == 1) {
    cout << *max_element(all(v)) << endl;
    return;
  }
  multiset<int> ms;
  int sum = 0;
  for (int i = 0; i + 1 < m; i++) {
    ms.insert(v[i]);
    sum += v[i];
  }
  int ans = -4e18;
  for (int i = m - 1; i < n; i++) {
    int tans = m * 1ll * v[i] - sum;
    ans = max(ans, tans);
    // cerr << tans << endl;
    if (!ms.empty() && v[i] < *(--ms.end())) {
      sum -= *(--ms.end());
      //   cerr << *(--ms.end()) << endl;
      ms.erase(--ms.end());
      ms.insert(v[i]);
      sum += v[i];
      //   cerr << sum << endl;
    }
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