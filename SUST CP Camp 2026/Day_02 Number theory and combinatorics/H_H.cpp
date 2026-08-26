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
  int n, q;
  cin >> n >> q;
  vector<int> v(n), pf(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    // cout << v[i] << endl;
    if (v[i] == 3 || v[i] == 4 || v[i] == 6) {
      pf[i]++;
    }
    if (i)
      pf[i] += pf[i - 1];
  }
  //   return;
  while (q--) {
    int l, r;
    cin >> l >> r;
    r--, l--;
    cout << pf[r] - (l ? pf[l - 1] : 0) << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //   int t;
  //   cin >> t;
  //   while (t--) {
  //     marwan();
  //   }
  marwan();
  return 0;
}