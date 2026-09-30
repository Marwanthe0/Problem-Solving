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
void marwan(int cs) {
  int n;
  cin >> n;
  vector<int> v(n), vis(105, 0);
  for (auto &vl : v) {
    cin >> vl;
    vis[vl]++;
  }
  int mex = 0, sum = 0, mx = *max_element(all(v));
  while (vis[mex]) {
    mex++;
  }
  for (int i = 0; i <= mx; i++) {
    if (i > mex) {
      sum += vis[i] * (i - (mex + 1));
    } else if (i < mex) {
      sum += (vis[i] - 1) * (i);
    }
  }
  //   cerr << mex << " " << sum << endl;
  if (sum & 1)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
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