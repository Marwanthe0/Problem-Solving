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
  int zr = count(all(v), 0);
  vector<int> dif(n + 1, 0), tif(n + 1, 0);
  set<int> ans;
  if (zr)
    dif[0]++, dif[1]--;

  for (int i = 0; i < n; i++) {
    int y = i + 1;
    if (v[i] * y < n) {
      dif[v[i] * (y)]++;
      dif[min(n, y * (v[i] + 1))]--;
    }
    // for (int j = 0; j <= v[i] - 1; j++) {
    //   if (j == 0) {
    //     tif[0]++;
    //     if (y <= n)
    //       tif[y]--;
    //   } else {
    //     if (j * y >= 0 && j * y <= n)
    //       tif[j * y]++;
    //     if ((j + 1) * y >= 0 && (j + 1) * y <= n)
    //       tif[(j + 1) * y]--;
    //   }
    // }
  }

  for (int i = 0; i <= n; i++) {
    // cout << i << " ";
    if (i)
      dif[i] += dif[i - 1];
  }
  //   //   cout << endl;
  //   for (int i = 0; i < n; i++) {
  //     // cout << tif[i] << " ";
  //     if (tif[i])
  //       ans.insert(i);
  //   }
  //   cout << endl;
  for (int i = 0; i < n; i++) {
    if (!dif[i])
      ans.insert(i);
    // else if (ans.count(i))
    //   ans.erase(ans.find(i));
    // cout << dif[i] << " ";
  }
  //   cout << endl;
  cout << ans.size() << endl;
  for (auto vl : ans)
    cout << vl << " ";
  cout << endl;
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