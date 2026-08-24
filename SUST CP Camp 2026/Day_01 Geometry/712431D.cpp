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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n, m;
  cin >> n;
  vector<pair<int, int>> a(n), b;
  vector<int> a1, a2, b1, b2;
  for (auto &[x, y] : a) {
    cin >> x >> y;
    a1.push_back(x);
    a2.push_back(y);
  }
  cin >> m;
  b.assign(m, pair<int, int>());
  for (auto &[x, y] : b) {
    cin >> x >> y;
    b1.push_back(x);
    b2.push_back(y);
  }
  sort(all(a1));
  sort(all(a2));
  sort(all(b1));
  sort(all(b2));
  auto f = [&](long double a, long double b, long double x,
               long double y) -> pair<long double, long double> {
    if (b - a == y - x) {
      return {b - a, abs(x - a)};
    }
    long double l = INT_MIN, r = INT_MAX, tans = INT_MAX, tansval = INT_MAX;
    while (l <= r) {
      long double mid = l + (r - l) / 2;
      long double midx = mid - 0.5, midy = mid + 0.5;
      cerr << midx << " " << mid << " " << midy << ":::";
      long double ma = mid + a, mb = mid + b;
      long double mm =
          max({abs(y - ma), abs(y - mb), abs(x - ma), abs(x - mb)});
      ma = midx + a, mb = midx + b;
      long double mmx =
          max({abs(y - ma), abs(y - mb), abs(x - ma), abs(x - mb)});
      ma = midy + a, mb = midy + b;
      long double mmy =
          max({abs(y - ma), abs(y - mb), abs(x - ma), abs(x - mb)});
      cerr << mmx << " " << mm << " " << mmy << endl;
      if (mm < mmx && mm < mmy) {
        tans = mid, tansval = mm;
        break;
      } else if (mmx < mm && mm < mmy) {
        r = mid - 0.5;
      } else {
        l = mid + 0.5;
      }
    }
    return {tansval, tans};
  };

  long double ans_x =
      ((a1.back() - a1.front()) + (b1.back() - b1.front())) / 2.0;
  long double ans_y =
      ((a2.back() - a2.front()) + (b2.back() - b2.front())) / 2.0;
  cerr << fixed << setprecision(10) << ans_x << " " << ans_y << "\n";
  cout << fixed << setprecision(10) << sqrt(ans_x * ans_x + ans_y * ans_y)
       << endl;
  //   pair<long double, long double> aa =
  //       f(a1.front(), a1.back(), b1.front(), b1.back());
  //   cerr << endl;
  //   pair<long double, long double> bb =
  //       f(a2.front(), a2.back(), b2.front(), b2.back());
  //   long double ans = sqrt(aa.first * aa.first + bb.first * bb.first);
  //   cout << ans << " " << aa.second << " " << bb.second << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}