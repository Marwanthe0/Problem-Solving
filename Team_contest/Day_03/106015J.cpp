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
  int n, m, sum;
  cin >> n >> m >> sum;
  vector<vector<int>> v(n, vector<int>(m, 0)), pf(n + 5, vector<int>(m + 5, 0)),
      dif(n + 5, vector<int>(m + 5, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      pf[i + 1][j + 1] = v[i][j];
      pf[i + 1][j + 1] += pf[i + 1][j];
      //   pf[i + 1][j + 1]
      //   pf[i + 1][j + 1] += pf[i][j + 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      pf[i][j] += pf[i - 1][j];
  }
  //   for (auto vl : pf) {
  //     for (auto val : vl)
  //       cout << val << " ";
  //     cout << endl;
  //   }
  //   cout << endl;
  //   int count = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 1; k <= i; k++) {
        for (int l = 1; l <= j; l++) {
          int x = pf[i][j] - pf[i][l - 1] - pf[k - 1][j] + pf[k - 1][l - 1];
          if (x == sum) {
            dif[k][l]++;
            dif[k][j + 1]--;
            dif[i + 1][l]--;
            dif[i + 1][j + 1]++;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dif[i][j] += dif[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dif[i][j] += dif[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (dif[i][j]) {
        cout << v[i - 1][j - 1] << " ";
      } else
        cout << 0 << " ";
    }
    cout << endl;
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}