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
set<int> hobe, hobena;
void marwan() {
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (hobe.count(v[i]))
      ans++;
  }
  cout << ans << " ";
  while (q--) {
    int pos, val;
    cin >> pos >> val;
    pos--;
    int tans = hobe.count(v[pos]);
    ans -= tans;
    v[pos] = val;
    tans = hobe.count(val);
    ans += tans;
    cout << ans << " ";
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //   for (int i = 0; i < 16; i++) {
  //     for (int j = i + 1; j < 16; j++) {
  //       for (int k = 3; k <= 15; k += 3) {
  //         int x = i ^ k, y = j ^ k;
  //         if (x % 3 == 0 && y % 3 == 0)
  //           m[{i, j}] = 2;
  //         else if (x % 3 == 0 || y % 3 == 0)
  //           m[{i, j}] = max(m[{i, j}], 1ll);
  //         else
  //           m[{i, j}] = 0;
  //       }
  //     }
  //   }
  for (int i = 0; i <= 15; i++) {
    bool flag = false, flag2 = true;
    for (int k = 3; k <= 15; k += 3) {
      int x = i ^ k;
      if (x % 3 == 0)
        flag = true;
    }
    if (flag)
      hobe.insert(i);
  }
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}