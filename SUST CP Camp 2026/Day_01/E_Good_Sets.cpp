#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
// vector<int> spf(N, 0);
// void pre() {
//   for (int i = 2; i * i <= N; i++) {
//     if (!spf[i]) {
//       for (int j = i; j <= N; j += i) {
//         spf[j] = i;
//       }
//     }
//   }
//   for (int i = 1; i <= N; i++)
//     if (!spf[i])
//       spf[i] = i;
// }
void marwan() {
  int n;
  cin >> n;
  int mx = INT_MIN;
  vector<int> v(n);
  for (auto &vl : v) {
    cin >> vl;
    mx = max(mx, vl);
  }
  vector<int> dp(mx + 1, 0ll);
  //   map<int, int> m;
  vector<int> m(mx + 1, 0);
  for (auto vl : v) {
    m[vl]++;
    dp[vl] = 1;
  }
  for (int i = 1; i <= mx; i++) {
    if (m[i]) {
      for (int j = 2 * i; j <= mx; j += i) {
        if (m[j])
          dp[j] = (dp[j] + dp[i]) % M;
      }
    }
  }
  int sum = 0ll;
  for (auto vl : v) {
    sum = (sum + dp[vl]) % M;
  }
  cout << sum << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //   pre();
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}