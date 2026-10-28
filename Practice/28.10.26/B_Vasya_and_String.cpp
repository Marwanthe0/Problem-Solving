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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int l = 0, r = 0, ans = 0;
  multiset<int> ms;
  map<char, int> m;
  while (r < n) {
    if (ms.count(m[s[r]]))
      ms.erase(ms.find(m[s[r]]));
    m[s[r]]++;
    ms.insert(m[s[r]]);
    int mx = *(--ms.end());
    int rem = (r - l + 1) - mx;
    while (rem > k) {
      if (ms.count(m[s[l]]))
        ms.erase(ms.find(m[s[l]]));
      m[s[l]]--;
      ms.insert(m[s[l]]);
      mx = *(--ms.end());
      l++;
      rem = (r - l + 1) - mx;
    }
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