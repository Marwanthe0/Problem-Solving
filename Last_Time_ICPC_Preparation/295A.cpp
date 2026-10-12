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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> dif(n + 1, 0), dif2(m + 1, 0);
  vector<tuple<int, int, int>> ops(m);
  for (int i = 0; i < m; i++) {
    auto &[x, y, z] = ops[i];
    cin >> x >> y >> z;
    x--, y--;
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    dif2[a]++, dif2[b + 1]--;
  }
  for (int i = 0; i < dif2.size(); i++) {
    if (i)
      dif2[i] += dif2[i - 1];
    if (i >= ops.size())
      continue;
    auto &[x, y, z] = ops[i];
    z *= dif2[i];
    // cerr << x << " " << y << " " << z << endl;
    dif[x] += z, dif[y + 1] -= z;
  }
  for (int i = 1; i < n; i++)
    dif[i] += dif[i - 1];
  for (int i = 0; i < n; i++)
    cout << v[i] + dif[i] << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}