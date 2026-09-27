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
int f(int x) {
  int sum = 0;
  while (x)
    sum += (x % 10) * (x % 10), x /= 10;
  return sum;
}
void marwan() {
  int n;
  cin >> n;
  vector<map<int, int>> t(50);
  vector<int> v(n);
  for (auto &vl : v) {
    cin >> vl;
    int x = vl;
    for (int i = 0; i < 50; i++) {
      t[i][x]++;
      x = f(x);
    }
  }
  int ans = 0;
  for (int i = 0; i < 50; i++) {
    cerr << i << endl;
    int tsum = 0;
    for (auto [x, y] : t[i]) {
      tsum += y * (y - 1) / 2;
      // cerr << x << " " << y << endl;
    }
    ans = max(ans, tsum);
    // cerr << endl;
  }
  cout << ans << endl;
  // cerr << endl;
  // cerr << endl;
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