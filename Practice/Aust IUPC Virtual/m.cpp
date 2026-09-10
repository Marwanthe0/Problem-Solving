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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int l = 1ll, r = 1e16, ans = 0;
  auto ok = [&](int mid) {
    int sum = 0ll;
    for (auto vl : v) {
      if (sum + (vl / mid) > k)
        return false;
      sum += (vl / mid);
    }
    return sum <= k;
  };
  while (l <= r) {
    int mid = l + (r - l) / 2ll;
    if (ok(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}