#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
  vector<int> v(n);
  vector<int> pf(n, 0), pfmax(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    pf[i] = pfmax[i] = v[i];
    if (i)
      pf[i] += pf[i - 1], pfmax[i] = max(pfmax[i], pfmax[i - 1]);
  }
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (pf[i] - pfmax[i] <= k) {
      cout << i + 1 << endl;
      return;
    }
  }
  cout << 1 << endl;
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