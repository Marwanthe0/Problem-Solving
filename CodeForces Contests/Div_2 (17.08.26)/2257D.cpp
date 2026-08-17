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
  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> divs;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divs.push_back({i, n / i});
      divs.push_back({n / i, i});
    }
  }
  sort(all(divs));
  while (q--) {
    map<int, int> m;
    int x, y;
    cin >> x >> y;
    for (auto [i, j] : divs) {
      int ii = min(i, x), jj = min(j, y);
    //   cerr << ii << " " << jj << endl;
      m[jj] = ii;
    }
    int last = 0, sum = 0ll;
    for (auto [i, j] : m) {
      sum += (i - last) * j;
      last = i;
    }
    cout << sum << endl;
    // cerr << endl;
  }
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