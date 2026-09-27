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
  while (x) {
    int y = x % 10;
    sum += y * y;
    x /= 10;
  }
  return sum;
}
int ff(int x) {
  for (int step = 0; step < 100; step++) {
    x = f(x);
  }
  return x;
}
// int ff(int x, bool flag) {
//   if (x < 10 && flag == true)
//     return m[x] = x;
//   int sum = 0, fg = x < 10;
//   if (m.count(x))
//     return m[x];
//   while (x) {
//     int y = x % 10;
//     sum += y * y;
//     x /= 10;
//   }
//   return m[x] = ff(sum, flag || fg);
// }
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> m;
  for (auto &vl : v) {
    cin >> vl;
    m[ff(vl)]++;
    // cerr << m[vl] << " ";
  }
  //   cerr << endl;
  int ans = 0;
  for (auto &[val, count] : m) {
    ans += count * (count - 1) / 2;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //   m[1] = 1;
  //   for (int i = 2; i <= 1000; i++) {
  //     int x = f(i);
  //     if (!m.count(i)) {
  //       m[i] = ff(x, x < 10 ? 0 : 1);
  //     }
  //   }
  //   for (int i = 1; i <= 50; i++) {
  //     cout << i << " " << m[i] << endl;
  //   }
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}