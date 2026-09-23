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
  if (is_sorted(all(v))) {
    minus;
    return;
  }
  int l = 1, r = *max_element(all(v)), ans = -1;
  auto ok = [&](int x) -> bool {
    int s = 0;
    vector<int> t = v;
    for (int i = 0; i < n; i++) {
      if (t[i] >= x)
        s += t[i] - x, t[i] = x;
      else {
        int val = min(s, x - t[i]);
        t[i] += val;
        s -= val;
      }
    }
    // cerr << x << "::";
    // for (auto vl : t)
    //   cerr << vl << " ";
    // cerr << endl;
    return is_sorted(all(t));
  };
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid)) {
      ans = mid, l = mid + 1;
    } else
      r = mid - 1;
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