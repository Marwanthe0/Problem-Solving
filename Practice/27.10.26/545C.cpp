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
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (auto &[x, y] : v)
    cin >> x >> y;
  if (n <= 2) {
    cout << n << endl;
    return;
  }
  v[0].second = v[n - 1].second = 0;
  int last = v[0].first;
  int ans = 1;
  vector<int> pf(n, 0), lst(n, 0);
  pf[0] = 1;
  lst[0] = v[0].first;
  for (int i = 1; i + 1 < n; i++) {
    if (last < v[i].first - v[i].second) {
      last = v[i].first;
      ans++;
    } else if (v[i].first + v[i].second < v[i + 1].first) {
      ans++;
      last = v[i].first + v[i].second;
    }
    last = max(last, v[i].first);
  }
  ans++;
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}