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
  int g = 0, one = 0;
  for (auto &vl : v) {
    cin >> vl;
    g = __gcd(g, vl);
    if (vl == 1) {
      one++;
    }
  }
  if (g != 1) {
    minus;
    return;
  } else if (one) {
    cout << n - one << endl;
    return;
  }
  int sz = n;
  for (int i = 0; i < n; i++) {
    int g = v[i];
    for (int j = i + 1; j < n; j++) {
      g = __gcd(g, v[j]);
      if (g == 1) {
        sz = min(sz, j - i + 1);
        break;
      }
    }
  }
  cout << (sz - 1) + n - 1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}