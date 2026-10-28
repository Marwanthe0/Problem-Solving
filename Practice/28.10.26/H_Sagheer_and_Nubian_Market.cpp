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
  int l = 0, r = n, ans = 0, anscost = 0;
  auto ok = [&](int mid) -> pair<int, int> {
    vector<int> t;
    for (int i = 0; i < n; i++) {
      t.push_back(v[i] + mid * (i + 1));
    }
    sort(all(t));
    int sum = 0;
    for (int i = 0; i < mid; i++)
      sum += t[i];
    if (sum <= k)
      return {1, sum};
    else
      return {0, 0};
  };
  while (l <= r) {
    int mid = l + (r - l) / 2;
    pair<int, int> tans = ok(mid);
    if (tans.first)
      ans = mid, l = mid + 1, anscost = tans.second;
    else
      r = mid - 1;
  }
  cout << ans << " " << anscost << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}