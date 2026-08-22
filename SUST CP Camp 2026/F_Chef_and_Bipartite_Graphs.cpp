#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  int mn = n - 1, mx = ((n / 2) * ((n + 1) / 2)) + n;
  if (m < mn || m > mx) {
    minus;
    return;
  }
  vector<pair<int, int>> e;
  int x = n / 2, y = (n + 1) / 2;
  int deg = 1, edges = y;
  for (int i = 1; i < n; i += 2) {
    e.push_back({i, i + 1});
    if (i + 1 < n)
      e.push_back({i + 1, i + 2});
  }

  for (auto [x, y] : e)
    cerr << x << " " << y << endl;
  cerr << endl;
  edges = (int)e.size();
  int cnt = 1;
  while (deg < min(b, x) && edges < m) {
    deg++, edges += y;
    for (int i = 1; i < n; i += 2) {
      e.push_back({i, (i + cnt + 1) % n + 1});
      if (i + 1 < n) {
        e.push_back({i + 1, (i + 2 + cnt) % n + 1});
      }
    }
    cnt += 2;
  }

  for (auto [x, y] : e)
    cerr << x << " " << y << endl;
  cerr << endl;
  // deg = 1, edges = 1
  if (edges < m) {
    int lagbe = m - edges;
    edges += min(lagbe, n);
    for (int i = 1; i <= min(lagbe, n); i++)
      e.push_back({i, i});
    deg++;
  }
  if (deg < a || deg > b || edges != m) {
    minus;
    return;
  }

  for (auto [x, y] : e)
    cout << x << " " << y << endl;
  cout << endl;
  // return;
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