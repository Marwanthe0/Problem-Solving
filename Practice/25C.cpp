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
  int n;
  cin >> n;
  vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> v[i][j];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a][b] = v[b][a] = min(v[a][b], c);
    for (int k = 1; k <= n; k++) {
      v[a][b] = min(v[a][b], v[a][k] + v[k][b]);
    }
    for (auto k : {a, b}) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        }
      }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++)
        sum += v[i][j];
    }
    cout << sum << " ";
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}