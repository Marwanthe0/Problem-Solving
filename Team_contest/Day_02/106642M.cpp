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
  vector<int> a(n), b(n);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;
  map<int, int> m1, m2;
  map<pair<int, int>, int> m3;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (m1.count(a[i] - b[i])) {
      ans += m1[a[i] - b[i]];
    }
    if (m2.count(a[i] + b[i]))
      ans += m2[a[i] + b[i]];
    if (m3.count({a[i] - b[i], a[i] + b[i]}))
      ans -= m3[{a[i] - b[i], a[i] + b[i]}];
    m3[{a[i] - b[i], a[i] + b[i]}]++;
    m1[a[i] - b[i]]++;
    m2[a[i] + b[i]]++;
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