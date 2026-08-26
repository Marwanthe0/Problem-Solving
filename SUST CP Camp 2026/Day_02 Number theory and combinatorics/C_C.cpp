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

vector<vector<int>> a = {{1, 1}, {1, 0}};

vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
  vector<vector<int>> c = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        c[i][k] += a[i][j] * b[j][k];
      }
    }
  }

  return c;
}

vector<vector<int>> binexp(vector<vector<int>> &a, int b, int mod) {
  vector<vector<int>> ans = {{1, 0}, {0, 1}};

  while (b) {
    if (b & 1) {
      ans = mul(ans, a);

      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
          ans[i][j] %= mod;
    }

    a = mul(a, a);

    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        a[i][j] %= mod;

    b >>= 1;
  }

  return ans;
}

void marwan(int cs) {
  int a, b, n, m;
  cin >> a >> b >> n >> m;

  int mod = 1;

  for (int i = 0; i < m; i++)
    mod *= 10;

  if (n == 0) {
    cout << "Case " << cs << ": " << a % mod << endl;
    return;
  }
  if (n == 1) {
    cout << "Case " << cs << ": " << b % mod << endl;
    return;
  }
  vector<vector<int>> base = {{1, 1}, {1, 0}}, ans = binexp(base, n - 1, mod);

  int fn = (ans[0][0] * b + ans[0][1] * a) % mod;

  cout << "Case " << cs << ": " << fn << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++)
    marwan(i);

  return 0;
}