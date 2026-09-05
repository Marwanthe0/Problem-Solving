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
void marwan() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  vector<int> arr(n);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    arr[i] = v[i].first;
    v[i].second = i;
    m[v[i].first]++;
  }
  sort(all(v));
  string ans(n, '0');
  int a = 0, b = 0, c = 0;
  bool flag1 = true, flag2 = true, flag3 = true;
  for (int i = 0; i < n; i++) {
    if (flag1 && m[i] >= 3) {
      a++, b++, c++;
    } else if (flag2 && m[i] >= 2) {
      a++, b++, flag1 = false;
    } else if (m[i] >= 1) {
      flag1 = false, flag2 = false;
      if (i == 0)
        a++;
      else if ((a + b + c + 1) >= 2 * (a + 1))
        a++;
      break;
    } else
      break;
  }
  if ((a + b + c) >= (2 * max({a, b, c})))
    yes;
  else {
    no;
    return;
  }
  //   cout << a << " " << b << " " << c << endl;
  int ta = 0, tb = 0, tc = 0;
  for (auto [x, y] : v) {
    if (x == ta && ta < a) {
      ans[y] = 'A', ta++;
    } else if (x == tb && tb < b) {
      ans[y] = 'B', tb++;
    } else if (x == tc && tc < c) {
      ans[y] = 'C', tc++;
    } else
      ans[y] = 'C';
  }
  cout << ans << endl;
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