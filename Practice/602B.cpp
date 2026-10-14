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
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int l = 0, r = 0, ans = 1;
  multiset<int> ms;
  while (r < n) {
    ms.insert(v[r]);
    int mx = *(--ms.end()), mn = *ms.begin();
    while (mx - mn > 1) {
      ms.erase(ms.find(v[l]));
      mx = *(--ms.end()), mn = *ms.begin();
      l++;
    }
    if (mx - mn <= 1)
      ans = max(ans, r - l + 1);
    r++;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}