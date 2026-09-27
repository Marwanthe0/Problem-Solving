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
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(all(v));
  set<int> ans;
  if (abs(v[0].first - v[1].first) >= k)
    ans.insert(v[0].second);
  if (abs(v[n - 1].first - v[n - 2].first) >= k)
    ans.insert(v[n - 1].second);
  for (int i = 1; i + 1 < n; i++) {
    if (abs(v[i].first - v[i - 1].first) >= k &&
        abs(v[i].first - v[i + 1].first) >= k)
      ans.insert(v[i].second);
  }
  cout << ans.size() << endl;
  for (auto vl : ans)
    cout << vl + 1 << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}