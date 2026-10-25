#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> a, pf(n, 0), sf(n, 0), b;
  for (int i = 0, j = n - 1; i < n; i++, j--) {
    auto it = upper_bound(all(a), v[i]);
    if (it == a.end())
      a.push_back(v[i]);
    else
      *it = v[i];
    pf[i] = a.size();

    auto tt = upper_bound(all(b), -v[j]);
    if (tt == b.end())
      b.push_back(-v[j]);
    else
      *tt = -v[j];
    sf[j] = b.size();
  }
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (v[i] > v[i + 1]) {
      ans = max(ans, pf[i] + sf[i + 1]);
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}