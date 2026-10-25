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
string a, b, c, uttor;
int n, m, o, lcs;
int dp[101][101][101];
int nxt[101][256];
bool same[101][101];
void buildNext() {
  memset(same, 0, sizeof(same));
  memset(nxt, 0, sizeof(nxt));

  for (int k = 0; k <= o; k++) {
    same[k][0] = true;

    for (int len = 1; len <= min(k, o); len++) {
      same[k][len] = (c[k - 1] == c[len - 1]) && same[k - 1][len - 1];
    }
  }

  for (int k = 0; k < o; k++) {
    for (int ch = 0; ch < 256; ch++) {
      for (int len = min(o, k + 1); len >= 1; len--) {
        if ((unsigned char)c[len - 1] == ch && same[k][len - 1]) {
          nxt[k][ch] = len;
          break;
        }
      }
    }
  }
}
int f(int i, int j, int k) {
  if (k == o)
    return dp[i][j][k] = -1e9;
  if (i == n || j == m)
    return dp[i][j][k] = 0;
  if (dp[i][j][k] != -1)
    return dp[i][j][k];
  int ans = f(i + 1, j, k);
  ans = max(ans, f(i, j + 1, k));
  if (a[i] == b[j]) {
    if (c[k] == a[i])
      ans = max(ans, 1 + f(i + 1, j + 1, k + 1));
    else {
      int nk = nxt[k][(unsigned char)a[i]];

      if (nk < o) {
        ans = max(ans, 1 + f(i + 1, j + 1, nk));
      }
    }
  }
  return dp[i][j][k] = ans;
}
void f2(int i, int j, int k, string &t) {

  if (k == o)
    return;
  if (i == n || j == m) {
    uttor = t;
    return;
  }
  if (dp[i + 1][j][k] == dp[i][j][k])
    f2(i + 1, j, k, t);
  else if (dp[i][j + 1][k] == dp[i][j][k])
    f2(i, j + 1, k, t);

  if (a[i] == b[j]) {
    if (c[k] == a[i]) {
      if (dp[i][j][k] == 1 + dp[i + 1][j + 1][k + 1]) {
        t.push_back(a[i]);
        f2(i + 1, j + 1, k + 1, t);
        t.pop_back();
      }
    } else {
      int nk = nxt[k][(unsigned char)a[i]];
      if (nk < o && 1 + dp[i + 1][j][nk] == dp[i][j][k]) {
        t.push_back(a[i]);
        f2(i + 1, k + 1, nk, t);
        t.pop_back();
      }
    }
  }
}
void marwan() {
  cin >> a;
  cin >> b;
  cin >> c;
  n = a.size(), m = b.size(), o = c.size();
  buildNext();
  memset(dp, -1, sizeof(dp));
  lcs = f(0, 0, 0);
  if (lcs == 0) {
    cout << lcs << endl;
    return;
  }
  string t;
  f2(0, 0, 0, t);
  cout << uttor << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}