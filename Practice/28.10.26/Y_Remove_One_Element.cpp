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
  vector<int> v(n), pf(n, 1), sf(n, 1);
  for (auto &vl : v)
    cin >> vl;
  int cnt = 1, cnt2 = 1;
  int ans = 1;
  for (int i = 1, j = n - 2; i < n; i++, j--) {
    if (v[i] > v[i - 1])
      cnt++;
    else {
      cnt = 1;
    }
    pf[i] = cnt;

    if (v[j] < v[j + 1])
      cnt2++;
    else
      cnt2 = 1;
    ans = max(ans, max(cnt, cnt2));
    sf[j] = cnt2;
  }
  //   for (int i = 0; i < n; i++) {
  //     cout << pf[i] << " ";
  //   }
  //   cout << endl;
  //   for (int i = 0; i < n; i++) {
  //     cout << sf[i] << " ";
  //   }
  for (int i = 1; i + 1 < n; i++) {
    if (v[i + 1] > v[i - 1])
      ans = max(ans, pf[i - 1] + sf[i + 1]);
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}