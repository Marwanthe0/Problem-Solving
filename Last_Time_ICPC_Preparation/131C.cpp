#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1e18
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
void marwan() {
  int n, m, t;
  cin >> n >> m >> t;
  int ans = 0ll;
  for (int i = 4; i <= n; i++) {
    int j = t - i;
    if (j <= 0 || j > m)
      continue;
    // cerr << n << " " << i << "::" << nCr(n, i) << endl;
    // cerr << m << " " << j << "::" << nCr(m, j) << endl;
    ans += nCr(n, i) * 1ll * nCr(m, j);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  marwan();
  return 0;
}