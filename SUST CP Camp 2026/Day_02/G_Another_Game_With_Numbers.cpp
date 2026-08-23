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
  int n, k;
  cin >> n >> k;
  vector<int> v(k);
  for (auto &vl : v) {
    cin >> vl;
  }
  set<int> st;
  for (int i = 0; i < k; i++) {
    int x = v[i];
    bool flag = true;
    for (auto vl : st)
      if (x % vl == 0)
        flag = false;
    if (flag)
      st.insert(x);
  }
  v.clear();
  int ans = 0ll;
  for (auto vl : st)
    v.push_back(vl);
  auto lcm = [&](int a, int b) {
    int g = __gcd(a, b);
    __int128 tmp = (__int128)a / g * b;
    if (tmp > n)
      return n + 1;
    return (int)tmp;
  };
  for (int i = 1; i < (1 << k); i++) {
    int ml = 1ll;
    bool fl = true;
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        ml = lcm(ml, v[j]);
        if (ml > n) {
          fl = false;
          break;
        }
      }
    }
    if (!fl)
      continue;
    // vis[ml] = __builtin_popcount(i);
    if ((__builtin_popcount(i) & 1) && ml <= n)
      ans += n / ml;
    else
      ans -= n / ml;
  }
  //   for (int i = 1; i <= min(n, (int)N); i++) {
  //     if (vis[i]) {
  //       //   cout << i << " " << vis[i] << endl;
  //       if (vis[i] & 1) {
  //         ans += n / i;
  //       } else
  //         ans -= n / i;
  //     }
  //   }
  cout << n - ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}