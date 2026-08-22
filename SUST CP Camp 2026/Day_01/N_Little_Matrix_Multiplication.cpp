#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
  vector<vector<int>> a(2, vector<int>(2, 0)), b(2, vector<int>(2, 0)),
      c(2, vector<int>(2, 0));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      cin >> a[i][j];
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      cin >> b[i][j];
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++)
        c[i][k] += a[i][j] * b[j][k];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++)
      cout << c[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  marwan();
  return 0;
}