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
  vector<int> v(n), pf(n, 0);
  for (auto &vl : v)
    cin >> vl;
  reverse(all(v));
  for (int i = 0; i < n; i++) {
    pf[i] = v[i];
    if (i)
      pf[i] += pf[i - 1];
  }
  //   for (auto vl : v)
  //     cerr << vl << " ";
  //   cerr << endl;
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int sz = v.size();
      int nl = sz - l - 1, nr = sz - r - 1;
      //   cerr << nl << " " << nr << endl;
      cout << pf[nl] - (nr ? pf[nr - 1] : 0) << endl;
    } else {
      int x;
      cin >> x;
      v.push_back(x);
      pf.push_back(x + pf.back());
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}