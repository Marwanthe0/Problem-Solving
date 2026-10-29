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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  for (auto &vl : v) {
    for (auto &val : vl)
      cin >> val;
  }
  vector<int> ansr, ansc;
  for (int i = 0; i < n; i++) {
    int xr = 0;
    for (int j = 0; j < m; j++) {
      xr ^= v[i][j];
    }
    ansr.push_back(xr);
  }
//   cerr << endl;
  for (int j = 0; j < m; j++) {
    int xr = 0;
    for (int i = 0; i < n; i++) {
      xr ^= v[i][j];
    }
    ansc.push_back(xr);
  }
  int ans = accumulate(all(ansr), 0ll) + accumulate(all(ansc), 0ll);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mx = max(mx, (ansr[i] + ansc[j]) - (ansr[i] ^ ansc[j]));
      //   cerr << (v[i][j] ^ ansr[i]) << " " << (v[i][j] ^ ansc[j]) << " "
      //        << (ansr[i] ^ ansc[j]) << endl;
    }
    // cerr << endl;
  }
  //   cerr << endl;
  cout << ans - mx << endl;
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