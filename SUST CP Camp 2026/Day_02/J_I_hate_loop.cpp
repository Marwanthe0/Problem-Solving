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
  int n;
  cin >> n;
  vector<int> v(n), pf(n, 0ll);
  for (auto &vl : v)
    cin >> vl;
  for (int i = 0; i < n; i++) {
    pf[i] = v[i];
    if (i)
      pf[i] += pf[i - 1];
  }
  //   for (auto vl : pf)
  //     cerr << vl << " ";
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << pf[r] - (l ? pf[l - 1] : 0) << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}