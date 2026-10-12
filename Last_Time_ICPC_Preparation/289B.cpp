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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n, m, d;
  cin >> n >> m >> d;
  int mn = INT_MAX;
  n *= m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mn = min(mn, v[i]);
  }
  for (auto vl : v) {
    if ((vl - mn) % d != 0) {
      minus;
      return;
    }
  }
  sort(all(v));
  int mid1 = v[n / 2], mid2 = v[n / 2 - 1], ans1 = 0, ans2 = 0;
  for (auto vl : v)
    ans1 += abs(vl - mid1) / d, ans2 += abs(vl - mid2) / d;
  cout << min(ans1, ans2) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}