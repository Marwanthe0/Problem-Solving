#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 998244353
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
vector<int> fact(N + 5, 0ll), ifact(N + 5, 0ll);
int mod(int x, int m = M) { return (x % m + m) % m; }
int binexp(int a, int b) {
  int ans = 1ll;
  while (b) {
    if (b & 1)
      ans = mod(ans * 1ll * a);
    a = mod(a * 1ll * a);
    b >>= 1;
  }
  return mod(ans);
}
void pre() {
  fact[0] = 1ll;
  for (int i = 1; i <= N; i++)
    fact[i] = mod(fact[i - 1] * 1ll * i);
  ifact[N] = binexp(fact[N], M - 2);
  for (int i = N; i > 0; i--) {
    ifact[i - 1] = mod(ifact[i] * 1ll * i);
  }
}
int nCr(int n, int r) {
  if (n < r || r < 0)
    return 0ll;
  if (r == 0 || n == r)
    return 1ll;
  return mod(mod(fact[n] * 1ll * ifact[r]) * 1ll * ifact[n - r]);
}
void marwan(int cs) {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  //   int ans = 0ll, xx = fact[n - 1];
  //   for (int i = 0, j = n - k - i, tk = n - 1; i < n - k; i++, j--, tk--) {
  //     int tans = xx;
  //     // for (int tk = 0; tk < i; tk++, l--) {
  //     //   tans = mod(tans - fact[l] + M);
  //     // }
  //     xx = mod(xx - ((tk == n - 1) ? 0 : fact[tk]) + M);
  //     cerr << xx << endl;
  //     tans = mod(xx * 1ll * j);
  //     ans = mod(ans + tans);
  //   }
  //   cerr << endl;
  //   cout << mod(fact[n] - ans + M) << endl;
  int ans = mod(binexp(k, n - k) * 1ll * fact[k]);
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}