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
  int n, k;
  cin >> n >> k;
  if (k < n || k == 2 * n) {
    minus;
    return;
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  int mx;
  vector<vector<int>> v(n, vector<int>(n, 0));
  int count = 1;
  //   for (int i = 0; i < n; i++)
  //     v[i][i] = count++;
  int x = k - n + 1, y = k, j = n - 1;
  for (int i = 0; i < x; i++, j--) {
    v[n - 1][j] = y--;
  }
  j = max(0ll, j);
  for (int i = n - 2; i >= 0; i--) {
    v[i][j] = y--;
    j = max(0ll, j - 1);
  }
  mx = k + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (v[i][j])
        cout << v[i][j] << " ";
      else
        cout << mx++ << " ";
    }
    cout << endl;
  }
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