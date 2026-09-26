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
  int n, k;
  cin >> n >> k;
  int elems = n - k + 1;
  vector<int> v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  int tk = n - k + 1;
  int ans = 0ll;
  //   if (k <= n / 2) {
  //     ans = max(ans, accumulate(v.begin() + 1, v.begin() + 1 + tk, 0ll));
  //     cout << ans << endl;
  //     return;
  //   }
  for (int i = k; i <= n - k + 1; i++) {
    ans += v[i];
  }
  vector<int> pf(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    pf[i] = v[i];
    pf[i] += pf[i - 1];
  }
  //   int tsum = pf[tk - 1];
  //   for (int i = 0; i <= elems; i++) {
  //     int ultai = elems - i;
  //     ultai = n - ultai + 1;
  //     int sm1 = pf.back() - pf[ultai - 1];
  //     int thiki = tk + i - 1;
  //     // cerr << ultai << " " << thiki << endl;
  //     sm1 += pf[thiki] - tsum;
  //     ans = max(ans, sm1);
  //   }
  for (int i = 1; i <= min(tk, k - 1); i++) {
    ans += max(v[i], v[n - i + 1]);
  }
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