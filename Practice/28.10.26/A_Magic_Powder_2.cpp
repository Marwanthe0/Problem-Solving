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
void marwan() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;
  int l = 0, r = 1e10, ans = 0;
  auto ok = [&](int need) {
    int extra = 0;
    for (int i = 0; i < n; i++) {
      extra += max(0ll, (need * 1ll * a[i] - b[i]));
      if (extra > k)
        return false;
    }
    return extra <= k;
  };
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid, l = mid + 1;
    } else
      r = mid - 1;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}