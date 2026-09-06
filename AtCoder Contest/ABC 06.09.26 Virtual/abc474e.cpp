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
void marwan() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n), t;
  int mn = INT_MAX;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    mn = min(mn, v[i].first);
  }
  int ans = 0ll;
  for (int i = 0; i < n; i++) {
    if (v[i].first > v[i].second + mn) {
      ans += v[i].second + mn;
    } else
      t.push_back(v[i]);
  }
    cout << ans << endl;
  //   return;
  v.clear();
    v = t;
  sort(all(v), [&](pair<int, int> a, pair<int, int> b) {
    return a.first - a.second < b.first - b.second;
  });
  for (auto vl : v)
    cerr << vl.first << " " << vl.second << endl;
  cerr << endl;
  int i = 0, j = n - 1;
  while (i <= j) {
    if (i == j)
      ans += v[i].first;
    else
      ans += v[i].first + v[j].second;
    i++, j--;
  }
  cout << ans << endl;
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