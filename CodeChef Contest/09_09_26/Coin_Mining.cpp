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
  int x, y;
  cin >> x >> y;
  int ans = LLONG_MAX;
  int yy = 0;
  int xx = 0;
  for (int i = 1; i <= x + y; i++) {
    yy += x;
    xx += y * i * i;
    int days;
    if (xx > yy) {
      days = i;
    } else {
      int lagbe = yy - xx;
      int aro = (lagbe / (y * i * i)) + 1;
      days = i + aro;
    }
    ans = min(ans, days);
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