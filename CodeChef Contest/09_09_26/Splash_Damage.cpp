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
  vector<int> v(n), t(n), pf(n, 0), sf(n + 1, 0), vis(n, 0), tt(n), skip1(n, 0),
      skip2(n + 1, 0);
  for (auto &vl : v)
    cin >> vl;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  t = v;
  tt = v;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == 3)
      ans++;
    else if (v[i] == 2) {
      if (i - 1 >= 0 && i + 1 < n && v[i - 1] == 0 && v[i + 1] == 1) {
      } else
        ans++;
    } else {
      if (i == 0 || v[i - 1] > 0)
        ans++, v[i] = 0;
      else
        skip1[i]++;
    }
    pf[i] = ans;
  }
  ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (t[i] == 3)
      ans++;
    else if (t[i] == 2) {
      if (i - 1 >= 0 && i + 1 < n && t[i + 1] == 0 && t[i - 1] == 1) {
      } else
        ans++;
    } else {
      if (i == n - 1 || t[i + 1] > 0)
        ans++, t[i] = 0;
      else
        skip2[i]++;
    }
    sf[i] = ans;
  }
  ans = 0;
  int tans = 0;
  for (int i = 0; i + 1 < n; i++) {
    // cerr << pf[i] << " ";
    if (pf[i] + sf[i + 2] + (tt[i + 1] == 3 || (skip1[i] || skip2[i + 2])) >
        ans) {
      ans = pf[i] + sf[i + 2] + (tt[i + 1] == 3 || (skip1[i] && skip2[i + 2])),
      tans = i;
    }
  }
  //   cerr << endl;
  //   for (int i = 0; i <= n; i++) {
  //     cerr << sf[i] << " ";
  //   }
  //   cerr << endl;

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