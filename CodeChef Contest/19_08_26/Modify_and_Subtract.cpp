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
  int n;
  cin >> n;
  vector<int> v(n), t, tt;
  for (auto &vl : v)
    cin >> vl;
  bool flag = true;
  for (auto vl : v)
    if (vl != v[0])
      flag = false;
  if (flag) {
    cout << n << endl;
    return;
  }
  t = v, tt = v;
  for (int i = 0, j = n - 1; i + 1 < n; i++, j--) {
    int mn = min(t[i], t[i + 1]);
    t[i] -= mn, t[i + 1] -= mn;
    mn = min(tt[j], tt[j - 1]);
    tt[j] -= mn, tt[j - 1] -= mn;
  }
  flag = true;
  for (auto vl : t) {
    if (vl) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << n << endl;
    return;
  }
  flag = true;
  for (auto vl : tt) {
    if (vl) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << n << endl;
    return;
  }
  //   int eve = 0, odd = 0;
  //   for (int i = 0; i < n; i++) {
  //     if (i & 1)
  //       odd += v[i];
  //     else
  //       eve += v[i];
  //   }
  //   if (eve == odd) {
  //     cout << n << endl;
  //     return;
  //   }
  vector<int> pf(n, 0), sf(n, 0);
  pf[0] = sf[n - 1] = 1;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur = v[i] - cur;
    if (cur < 0)
      break;
    pf[i] = 1;
  }
  cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    cur = v[i] - cur;
    if (cur < 0)
      break;
    sf[i] = 1;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (sf[i + 1]) {
        count++;
      }
    } else if (i == n - 1) {
      if (pf[i - 1]) {
        count++;
      }
    } else if (pf[i - 1] && sf[i + 1]) {
      count++;
    }
  }
  cout << count << endl;
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