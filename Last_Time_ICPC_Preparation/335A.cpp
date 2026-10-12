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
  string s;
  cin >> s;
  int k;
  cin >> k;
  map<char, int> m;
  for (auto c : s)
    m[c]++;
  if (k < m.size()) {
    minus;
    return;
  }
  int l = 1, r = 0, ans = 1;
  for (auto [_, x] : m)
    r = max(r, x);
  auto ok = [&](int mid) {
    int sum = 0;
    for (auto [x, y] : m)
      sum += (y / mid) + (y % mid != 0);
    return sum <= k;
  };
  while (l <= r) {
    int mid = l + (r - l) / 2;
    bool kk = ok(mid);
    // cerr << mid << " " << kk << endl;
    if (kk) {
      r = mid - 1, ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  string uttor;
  for (auto [x, y] : m) {
    int lim = y / ans + (y % ans != 0);
    for (int i = 0; i < lim; i++)
      uttor.push_back(x);
  }
  while (uttor.size() < k)
    uttor.push_back(s[0]);
  cout << uttor << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}