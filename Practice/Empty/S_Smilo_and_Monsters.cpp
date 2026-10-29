#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  int l = 0, r = n - 1;
  int ans = 0, sum = 0;
  for (auto vl : v)
    cout << vl << " ";
  cout << endl;
  while (l < r) {
    if (sum < v[r])
      sum += v[l++];
    if (sum >= v[r]) {
      ans += v[r] + 1, l++, r--;
      sum -= v[r];
    }
  }
  //   if (sum == v[r]) {
  //     ans += sum + 1, l++, r--;
  //     sum = 0;
  //   }
  //   if (l == r)
  //     ans += min(sum + v[l], (sum + v[l] + 3) / 2);
  cout << ans << " " << sum << " " << l << " " << r << endl;
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}