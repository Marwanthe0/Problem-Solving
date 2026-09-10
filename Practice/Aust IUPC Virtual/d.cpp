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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (auto &vl : v)
    cin >> vl.first >> vl.second;
  sort(all(v),
       [&](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  int last1 = -1, last2 = -1, ans = 0;
  for (int i = 0; i < n; i++) {
    if (v[i].first >= last1) {
      last1 = v[i].second, ans++;
    } else if (v[i].first >= last2) {
      last2 = v[i].second, ans++;
    }
    if (last1 < last2)
      swap(last1, last2);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}