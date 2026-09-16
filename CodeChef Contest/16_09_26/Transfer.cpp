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
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> pf(n + 1, 0), tf(n + 1, 0);
  for (int i = 0, j = n; i < n; i++, j--) {
    pf[i] += v[i] * 1ll * j;
    tf[i] = j;
    // if (i) {
    //   tf[i] += tf[i - 1];
    //   pf[i] += pf[i - 1];
    // }
  }
  for (int i = n - 2; i >= 0; i--)
    pf[i] += pf[i + 1], tf[i] += tf[i + 1];
  for (int i = 0; i <= n; i++)
    cerr << pf[i] << " ";
  cerr << endl;
  for (int i = 0; i <= n; i++)
    cerr << tf[i] << " ";
  cerr << endl;
  int tsum = accumulate(all(v), 0ll), count = n, l = 0, r = -1, ans = 0ll;
  int x = (tsum / count) + (tsum % count != 0);
  int y = tsum / count;
  l = 0, r = n - 1;
  int ll = pf[l] - (pf[r + 1]);
  int rr = y * 1ll * (tf[l] - tf[r + 1]);
  int yy = tsum % count;
  if (yy)
    yy = tf[r - (yy - 1)] - tf[r + 1];
  rr += yy;
  int tans = max(0ll, ll - rr);
  ans += tans;
  cout << ans << endl;
  return;
  for (int i = 1; i >= n - 1; i++) {
    int x = (tsum / count) + (tsum % count != 0);
    int y = tsum / count;
    if (x > v[i])
      tsum += v[i], count++;
    else {
      r = i - 1;
      int ll = pf[l] - (pf[r + 1]);
      int rr = y * 1ll * (tf[l] - tf[r + 1]);
      int yy = tsum % count;
      if (yy)
        yy = tf[r - (yy - 1)] - tf[r + 1];
      rr += yy;
      int tans = abs(ll - rr);
      ans += tans;
      //   cout << l << " " << r << " " << tsum << " " << count << " " << x << "
      //   "
      //        << ll << " " << rr << " " << tans << endl;
      l = i;
      tsum = v[i], count = 1ll;
    }
  }
  if (count > 1) {
    int x = tsum / count + (tsum % count != 0);
    int y = tsum / count;
    r = n - 1;
    int ll = pf[l] - pf[r + 1];
    int rr = y * (tf[l] - tf[r + 1]);
    int yy = tsum % count;
    if (yy)
      yy = tf[r - (yy - 1)] - tf[r + 1];
    rr += yy;
    int tans = abs(ll - rr);
    ans += tans;
    // cout << l << " " << r << " " << tsum << " " << count << " " << x << " "
    //      << ll << " " << rr << " " << tans << endl;
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