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
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  int l = v[n / 2], r = k + l, ans = l;

  auto ok = [&](int mid) {
    int sum = 0;
    for (int i = (n / 2); i < n; i++) {
      if (v[i] < mid)
        sum += mid - v[i];
      else
        break;
    }
    return sum <= k;
  };
  while (l <= r) {
    int mid = l + (r - l) / 2;
    bool kk = ok(mid);
    if (kk) {
      l = mid + 1, ans = mid;
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