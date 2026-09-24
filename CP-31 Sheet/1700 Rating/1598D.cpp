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
  vector<pair<int, int>> v(n);
  map<int, int> a, b;
  map<pair<int, int>, int> c;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    a[v[i].first]++;
    b[v[i].second]++;
    c[{v[i].first, v[i].second}]++;
  }
  int f1 = 0, pair1 = 0, ans1 = 0, f2 = 0, pair2 = 0, ans2 = 0;
  auto nc3 = [&](int x) { return (x * 1ll * (x - 1) * (x - 2)) / 6ll; };
  int ans3 = nc3(n);
  for (auto [x, y] : a) {
    ans1 += pair1 * y;
    pair1 += y * f1;
    f1 += y;
    if (y >= 3) {
      ans3 -= nc3(y);
    }
    if (y >= 2) {
      ans3 -= (n - y) * 1ll * (y * 1ll * (y - 1) / 2ll);
    }
  }
  cout << ans3 << endl;
  for (auto [x, y] : b) {
    ans2 += pair2 * 1ll * y;
    pair2 += y * 1ll * f2;
    f2 += y;
    if (y >= 3) {
      ans3 -= nc3(y);
    }
    if (y >= 2) {
      ans3 -= (n - y) * 1ll * (y * 1ll * (y - 1) / 2ll);
    }
  }
  cout << ans1 << " " << ans2 << " " << ans3 << endl;
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