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
  int n, d, k;
  cin >> n >> d >> k;
  vector<int> dif(n + 2, 0);
  vector<vector<int>> op(n + 1, vector<int>());
  vector<vector<int>> cl(n + 2, vector<int>());
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    op[a].push_back(i);
    cl[b + 1].push_back(i);
  }
  cerr << endl;
  int l = 1, r = 1;
  multiset<int> ms;
  int mxsum = INT_MIN, mnsum = INT_MAX, mxp = 0, mnp = 0, dist = 0;
  map<int, int> m;
  while (r <= n) {
    for (auto job : op[r]) {
      m[job]++;
      if (m[job] == 1)
        dist++;
    }
    if (r - l + 1 == d) {
      for (auto job : cl[l]) {
        m[job]--;
        if (m[job] == 0)
          dist--;
      }
      if (dist > mxsum)
        mxsum = dist, mxp = l;
      if (dist < mnsum)
        mnsum = dist, mnp = l;
      l++;
    }
    r++;
  }
  cout << mxp << " " << mnp << endl;
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