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
  int n, s, k;
  cin >> n >> s >> k;
  vector<int> v(n - 1), pf(n, 0);
  for (int i = 0; i < n - 1; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n - 1; i++) {
    pf[i + 1] = pf[i] + v[i];
  }
  int ans = 1ll;
  s--;
  for (int i = 0; i <= s; i++) {
    for (int j = s; j < n; j++) {
      int x = pf[s] - pf[i];
      x += pf[j] - pf[s];
      x += min(pf[s] - pf[i], pf[j] - pf[s]);
      //   cerr << i << " " << j << " " << x << endl;
      if (x <= k) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}