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
int binexp(int a, int b) {
  int ans = 1ll;
  while (b) {
    if (b & 1)
      ans = (ans * 1ll * a) % M;
    a = (a * 1ll * a) % M;
    b >>= 1;
  }
  return ans % M;
}
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  reverse(all(v));
  // for (int len = 1; len < n; len++) {
  //   int sum = 0;
  //   for (int i = 0; i + len < n; i++) {
  //     int j = i + len;
  //     cout << v[i] << " - " << v[j] << " = " << v[i] - v[j] << endl;
  //     sum += v[i] - v[j];
  //   }
  //   cout << sum << endl;
  // }
  // cout << endl;
  // return;
  int l = 0, r = n - 1, s1 = 0, s2 = 0, ans = 0ll, k1 = 0, k2 = n - 2;
  while (r - l > 1) {
    s1 += v[l];
    s2 += v[r];
    ans = (ans + ((s1 - s2) % M) * 1ll *
                     (((binexp(2, k1)) % M + (binexp(2, k2)) % M) % M) % M) %
          M;
    // cout << l << " " << r << " = " << (s1 - s2) << " "
    //      << (((binexp(2, k1)) + (binexp(2, k2))) % M) << endl;
    k1++, k2--;
    l++, r--;
  }
  if (n % 2 == 0) {
    s1 += v[l], s2 += v[r];
    ans = (ans + (((s1 - s2) % M) * 1ll * (binexp(2, k1) % M)) % M) % M;
    ans %= M;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}