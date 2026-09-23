#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int dp0 = (v[0] >= 0 ? v[0] : -1e17);
  int dp1 = 0;
  for (int i = 1; i < n; i++) {
    int new0 = (dp0 != -1e17 && dp0 + v[i] >= 0) ? (dp0 + v[i]) : -1e17;
    int cand1 = (dp1 != -1e17 && dp1 + v[i] >= 0) ? (dp1 + v[i]) : -1e17;
    int cand2 = (dp0 != -1e17) ? dp0 : -1e17;
    int new1 = max(cand1, cand2);
    // cerr << new0 << " " << new1 << endl;
    // cerr << cand1 << " " << cand2 << endl;
    dp0 = new0;
    dp1 = new1;
  }
  if (dp0 != -1e17 || dp1 != -1e17)
    yes;
  else
    no;
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