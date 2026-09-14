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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n, vector<int>(m, 0));
  vector<string> t(n);
  vector<int> row(n, 0), cols(m, 0), rw(n, 0), cls(m, 0);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    for (int j = 0; j < m; j++) {
      v[i][j] = t[i][j] - '0';
      cls[j] += v[i][j];
      rw[i] += v[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < m; j++) {
      if (v[i][j])
        count += cls[j] - 1;
    }
    row[i] = count;
  }
  for (int j = 0; j < m; j++) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (v[i][j])
        count += rw[i] - 1;
    }
    cols[j] = count;
  }
  //   for (auto vl : row)
  //     cout << vl << " ";
  //   cout << endl;
  //   for (auto vl : cols)
  //     cout << vl << " ";
  //   cout << endl;
  //   cout << endl;
  map<int, int> ans;
  int sum = accumulate(all(row), 0ll) + accumulate(all(cols), 0ll);
  cerr << sum << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!v[i][j]) {
        int x = sum - (row[i] + cols[j]);
        x += rw[i] * cls[j];
        ans[x]++;
      }
    }
  }
  cout << (--ans.end())->first << " " << (--ans.end())->second << endl;
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