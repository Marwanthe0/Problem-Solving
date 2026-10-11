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
  int mxval = v[0], mnval = v[0], ans = v[0];
  for (int i = 1; i < n; i++) {
    int op1 = v[i], op2 = v[i] - mxval, op3 = v[i] - mnval, op4 = v[i] + mxval,
        op5 = v[i] + mnval;
    ans = max(ans, max({op1, op2, op3, op4, op5}));
    mxval += max({mxval + });
    mnval += min({op1, op2, op3, op4, op5});
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