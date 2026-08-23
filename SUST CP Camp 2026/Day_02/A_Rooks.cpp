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
int nCr[35][35];

void pre() {
  for (int i = 0; i <= 30; i++) {
    nCr[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    }
  }
}

int P(int n, int k) {
  int res = 1;
  for (int i = 0; i < k; i++) {
    res *= (n - i);
  }
  return res;
}

void marwan(int cs) {
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << "Case " << cs << ": " << 0 << "\n";
    return;
  }
  if (k == 0) {
    cout << "Case " << cs << ": " << 1 << "\n";
    return;
  }
  int ans = nCr[n][k] * 1ll * P(n, k);
  cout << "Case " << cs << ": " << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}
