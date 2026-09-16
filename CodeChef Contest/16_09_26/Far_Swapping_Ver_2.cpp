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
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int ans = 0;
  set<pair<int, int>> s;
  pair<int, int> last = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (abs(v[j] - v[j - 1]) > 1) {
        if (min(v[j], v[j - 1]) == last.first &&
            max(v[j], v[j - 1]) == last.second)
          continue;
        swap(v[j], v[j - 1]);
        ans++;
        cerr << v[j] << " " << v[j - 1] << endl;
        last.first = min(v[j], v[j - 1]), last.second = max(v[j], v[j - 1]);
        break;
      }
    }
  }
  cerr << endl;
  cout << ans << endl;
  //   cout << s.size() << endl;
  //   for (auto vl : s)
  //     cout << vl.first << " " << vl.second << endl;
  //   cout << endl;
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