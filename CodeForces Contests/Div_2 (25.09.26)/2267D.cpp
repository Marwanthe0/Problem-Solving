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
  vector<int> par(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    par[x] = i & 1;
    // cerr<<par[x]<< " ";
  }
  int P = par[n];
  vector<array<bool, 2>> dp(n + 1);
  dp[0][0] = true;
  for (int k = 0; k < n - 1; k++) {
    int x = n - 1 - k;
    for (int s = 0; s < 2; s++) {
      if (!dp[k][s])
        continue;
      int rpar = (k & 1) ^ s, lpr = (P + 1 + s) & 1, rpr = (P + 1 + rpar) & 1;
      if (par[x] == lpr) {
        dp[k + 1][s ^ 1] = true;
      }
      if (par[x] == rpr) {
        dp[k + 1][s] = true;
      }
      //   cerr<<dp[k+ 1]<<" "
    }
  }
  cout << (dp[n - 1][P] ? "YES\n" : "NO\n");
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