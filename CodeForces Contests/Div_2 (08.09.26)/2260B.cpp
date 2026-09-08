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
  int x, y, k;
  cin >> x >> y >> k;
  int d = y - x;
  if (d == 0) {
    cout << 0 << endl;
    return;
  }

  int ans = 0;
  int up = min(x + k - 1, d);
  for (int a = x; a <= up; ++a) {
    ans += d % a;
  }

  if (x + k - 1 > d) {
    int more = (x + k - 1) - max(d, x - 1);
    ans += more * 1ll * d;
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