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
  int ans = 0, mx = *max_element(all(v));
  for (int j = 0; j <= __lg(mx); j++) {
    int even = 1, odd = 0, count = 0, oddval = 0, evenval = 0;
    for (int i = 0; i < n; i++) {
      count ^= 1 & (v[i] >> j);
      if (count & 1)
        ans += even, odd++;
      else
        ans += odd, even++;
    }
    cerr << ans << endl;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  marwan();
  return 0;
}