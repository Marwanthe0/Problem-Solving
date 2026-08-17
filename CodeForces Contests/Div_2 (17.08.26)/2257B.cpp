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
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;
  sort(all(a));
  sort(all(b));
  int x = 0ll, y = 0ll, last1 = 0, last2 = 0;
  for (int i = 0; i < n; i++) {
    x += a[i] - last1;
    // cerr << a[i] << " " << last1 << endl;
    last1 = a[i] - 1;
  }
  //   cerr << endl;
  for (int i = 0; i < m; i++) {
    y += b[i] - last2;
    // cerr << b[i] << " " << last2 << endl;
    last2 = b[i] - 1;
  }
  //   cerr << x << " " << y << endl;
  //   cerr << endl;
  //   cerr << endl;
  if (x >= y) {
    cout << 1 << endl;
  } else
    cout << 2 << endl;
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