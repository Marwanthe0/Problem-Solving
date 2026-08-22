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
void marwan(int cs) {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int f1 = 0, f2 = 0, f3 = 0, t1 = 0, t2 = 0, t3 = 0;
  if (a == 0 || c == 0 || e == 0) {
    cout << "Case " << cs << ": ";
    cout << 1 << endl;
    return;
  }
  if (a) {
    while (a % 5 == 0) {
      a /= 5;
      f1++;
    }
    if (a) {
      while (a % 2 == 0) {
        a /= 2;
        t1++;
      }
    }
  }
  if (c) {
    while (c % 5 == 0) {
      c /= 5;
      f2++;
    }
    if (c) {
      while (c % 2 == 0) {
        c /= 2;
        t2++;
      }
    }
  }
  if (e) {
    while (e % 5 == 0) {
      e /= 5;
      f3++;
    }
    if (e) {
      while (e % 2 == 0) {
        e /= 2;
        t3++;
      }
    }
  }

  f1 = b * 1ll * f1, t1 = b * 1ll * t1;
  f2 = d * 1ll * f2, t2 = d * 1ll * t2;
  f3 = f * 1ll * f3, t3 = f * 1ll * t3;
  cout << "Case " << cs << ": ";
  cout << min((f1 + f2 + f3), (t1 + t2 + t3)) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++)
    marwan(i);
  return 0;
}