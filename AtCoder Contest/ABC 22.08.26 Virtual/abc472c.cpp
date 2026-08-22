#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int j = 0, tsum = 0;
  vector<int> vis(n, 0);
  for (int i = 0; i < n; i++) {
    if (tsum + v[i] <= k) {
      tsum += v[i];
      vis[i] = 1;
    }
    if (i >= m - 1) {
      if (vis[j])
        tsum -= v[j];
      j++;
    }
    // cout << tsum << endl;
  }
  for (int i = 0; i < n; i++)
    if (vis[i])
      yes;
    else
      no;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  marwan();
  return 0;
}