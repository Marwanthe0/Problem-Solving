#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 3000
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
vector<int> divs[N + 1];
void pre() {
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      divs[j].push_back(i);
    }
  }
}
int n, k;
vector<int> v;
// int f(int i, int count, int last) {
//   if (count == k)
//     return 1;
//   if (i >= n)
//     return 0;
//   if (dp[i][count][last] != -1)
//     return dp[i][count][last];
//   int nibona = f(i + 1, count, last), nibo = 0;
//   if ((v[i] % v[last] == 0) || last == 0)
//     nibo = f(i, count + 1, i);
//   return dp[i][count][last] = (nibo + nibona);
// }
void marwan() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    v.push_back(i);
  //   cout << f(0, 0, 0) << endl;
  //   return;

  vector<vector<int>> cur(k + 1, vector<int>(n + 1, 0));
  for (int i = n; i >= 0; i--) {
    for (int last = i; last >= 0; last--)
      cur[k][last] = 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int count = k - 1; count >= 0; count--) {

      for (auto d : divs[v[i]]) {
        cur[count][d - 1] = (cur[count][d - 1] + cur[count + 1][i]) % M;
      }
      //   for (int last = i; last >= 0; last--) {
      //     if ((v[i] % v[last]) == 0) {
      //       cur[count][last] = (cur[count][last] + cur[count + 1][i]) % M;
      //     }
      //   }
    }
  }
  cout << cur[0][0];
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  marwan();
  return 0;
}