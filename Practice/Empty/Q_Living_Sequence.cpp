#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int f(int x) {
  int sz = to_string(x).size();
  sz = pow(10, sz - 1);
  sz *= (to_string(x)[0] - '0');
  return sz;
}
void marwan(int cs) {
  int n;
  cin >> n;
  int l = 0, r = 1e18, ans = n;
  vector<int> pf(19, 0ll);
  int prev = 1ll;
  for (int i = 1ll, j = 10ll; i <= 16; i++, j = (j * 1ll * 10ll)) {
    pf[i] = prev;
    prev = j + prev * 9ll;
  }
  auto ok = [&](int val) -> int {
    int sum = 0;
    while (val) {
      int t = f(val);
      int sz = to_string(val).size();
      int first = to_string(val)[0] - '0';
      int tans = pf[sz - 1];
      if (first > 4) {
        sum += t / first;
      } else if (first == 4) {
        sum += val - t + 1;
      }
      sum += (tans) * (first - (first > 4));
    //   cerr << "val = " << val << " ";
    //   cerr << "t = " << t << " ";
    //   cerr << "sz = " << sz << " ";
    //   cerr << "first = " << first << " ";
    //   cerr << "tans = " << tans << " ";
    //   cerr << "sum = " << sum << " ";
      val -= t;
      //   cerr << endl;
    }
    return sum;
  };
  cout << ok(13399) << endl;
  return;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    int val = mid - ok(mid);
    if (val >= n) {
      r = mid - 1, ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}