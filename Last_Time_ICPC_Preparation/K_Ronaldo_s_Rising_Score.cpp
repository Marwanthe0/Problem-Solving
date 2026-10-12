// #include <bits/stdc++.h>
// using namespace std;
// // #define int long long
// #define M 1000000007
// #define N 1000005
// #define INF 1e17
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define minus cout << "-1" << endl
// #define zero cout << "0" << endl
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define make_unique(x) \
//   sort(all((x))); \ (x).erase(unique(all((x))), (x).end())
// int n, m;
// vector<int> a, b;
// vector<vector<vector<int>>> dp;
// int f(int i, int j, int last) {
//   if (i > n || j > m)
//     return 0;
//   if (dp[i][j][last] != -1)
//     return dp[i][j][last];
//   int nibona1 = f(i + 1, j, last), nibona2 = f(i, j + 1, last), nibo = 0;
//   if (a[i] == b[j] && (a[last] < a[i]))
//     nibo = f(i + 1, j + 1, i) + 1;
//   return dp[i][j][last] = max({nibona1, nibona2, nibo});
// }
// void marwan() {
//   cin >> n;
//   a.assign(n + 1, 0);
//   a[0] = INT_MIN;
//   for (int i = 1; i <= n; i++)
//     cin >> a[i];
//   cin >> m;
//   b.assign(m + 1, 0);
//   dp.assign(n + 2, vector<vector<int>>(m + 2, vector<int>(n + 1, 0)));
//   for (int i = 1; i <= m; i++)
//     cin >> b[i];
//   for (int i = n; i >= 0; i--) {
//     for (int j = m; j >= 0; j--) {
//       for (int last = i; last >= 0; last--) {
//         dp[i][j][last] = max(dp[i + 1][j][last], dp[i][j + 1][last]);

//         if (a[i] == b[j] && a[last] < a[i])
//           dp[i][j][last] = max(dp[i][j][last], dp[i + 1][j + 1][i] + 1);
//       }
//     }
//   }
//   int ans = dp[1][1][0];
//   cout << ans << endl;
//   int i = 1, j = 1, k = 0;
//   while (i <= n && j <= m) {
//     int best = dp[i][j][k];

//     if (a[i] == b[j] && a[k] < a[i] && best == dp[i + 1][j + 1][i] + 1) {
//       cout << a[i] << " ";
//       k = i;
//       i++, j++;

//     } else {
//       if (dp[i + 1][j][k] == best)
//         i++;
//       else
//         j++;
//     }
//   }
//   cout << endl;
// }
// int32_t main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   marwan();
//   return 0;
// }

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
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (auto &vl : a)
    cin >> vl;
  cin >> m;
  vector<int> b(m);
  for (auto &vl : b)
    cin >> vl;
  vector<int> dp(n, 0);
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < m; j++) {
      if (a[i] == b[j]) {
        dp[j] = max(dp[j], cur + 1);
      } else if (a[i] > b[j])
        cur = max(dp[j], cur);
    }
  }
  int mx = max_element(all(dp)) - dp.begin();
  cout << dp[mx] << endl;
  for (auto vl : dp)
    cout << vl << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}