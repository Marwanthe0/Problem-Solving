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
  string s;
  cin >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      v[i] = 1;
    else
      v[i] = -1;
    if (i)
      v[i] += v[i - 1];
  }
  map<int, int> m;
  int ans = 0;
  m[0] = -1;
  for (int i = 0; i < n; i++) {
    if (m.count(v[i]))
      ans = max(ans, i - m[v[i]]);
    if (!m.count(v[i]))
      m[v[i]] = i;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}