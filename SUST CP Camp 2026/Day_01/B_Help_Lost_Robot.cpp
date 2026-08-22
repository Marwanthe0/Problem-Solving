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
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  if ((a != x) && (b != y)) {
    cout << "sad" << endl;
  } else {
    if (a == x) {
      if (b < y)
        cout << "up" << endl;
      else
        cout << "down" << endl;
    } else {
      if (a < x)
        cout << "right" << endl;
      else
        cout << "left" << endl;
    }
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