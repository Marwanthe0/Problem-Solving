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
  vector<int> a(n), b(n), c(n, INT_MAX);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        c[i] = min(c[i], b[i] + b[j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    int mx = INT_MAX;
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        mx = min(mx, c[j]);
      }
    }
    c[i] = mx + b[i];
    // cout << c[i] << " ";
  }
  //   cout << endl;
  int ans = *min_element(all(c));
  if (ans >= INT_MAX)
    cout << -1 << endl;
  else
    cout << *min_element(all(c)) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}