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
  if (((n * (n + 1)) / 2) & 1) {
    minus;
    return;
  }
  map<int, int> m;
  int target = (n * (n + 1)) / 4;
  m[0] = 0;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
    // cerr << m.count(sum - target) << " " << sum << " " << target << endl;
    if (m.count(sum - target)) {
      for (int j = 1; j <= m[sum - target]; j++) {
        cout << 'a';
      }
      for (int j = m[sum - target] + 1; j <= i; j++) {
        cout << 'b';
      }
      for (int j = i + 1; j <= n; j++) {
        cout << 'a';
      }
      cout << endl;
      return;
    }
    m[sum] = i;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}