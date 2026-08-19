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
  int s, q;
  cin >> s >> q;
  vector<int> divs, intervals;
  map<int, int, greater<int>> m, tm;
  for (int i = 1; i * i <= s; i++) {
    if (s % i == 0) {
      m[i] = s / i;
      m[s / i] = i;
      divs.push_back(i);
      if (s / i != i)
        divs.push_back(s / i);
    }
  }
  make_unique(divs);
  int last = 0;
  for (auto vl : divs) {
    intervals.push_back(vl - last);
    last = vl;
  }
  int sum = 0ll, sz = divs.size();
  for (int i = 0; i < sz; i++) {
    sum += divs[i] * 1ll * intervals[sz - i - 1];
  }
  // cout << sum << endl;
  last = 0;
  // for (auto vl : divs)
  //   cerr << vl << " ";
  // cerr << endl;
  // for (auto vl : divs)
  //   cerr << s / vl << " ";
  // cerr << endl;
  // for (auto vl : intervals)
  //   cerr << vl << " ";
  // cerr << endl;
  int lastsum = 0, lastval = 0;
  for (auto [x, y] : m) {
    // cerr << x << " " << y << endl;
    lastsum += (last - x) * lastval;
    tm[x] = lastsum;
    last = x, lastval = y;
  }
  // cerr << endl;
  lastsum += (last)*lastval;
  tm[0] = lastsum;
  // for (auto [x, y] : tm)
  //   cerr << x << " " << y << endl;
  // cerr << endl;
  // cerr << endl;
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    // cout << x << " " << y << endl;
    int tsum = sum;
    int ind1 = lower_bound(all(divs), x) - divs.begin(),
        ind2 = lower_bound(all(divs), y) - divs.begin();
    int xx = divs[ind1], yy = divs[ind2];
    xx = (tm[xx] + (xx - x) * m[xx]);
    yy = (tm[yy] + (yy - y) * m[yy]);
    tsum -= (xx + yy);
    ind2 = sz - ind2 - 1;
    if (ind1 <= ind2)
      cout << x * 1ll * y << endl;
    else
      cout << tsum << endl;
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