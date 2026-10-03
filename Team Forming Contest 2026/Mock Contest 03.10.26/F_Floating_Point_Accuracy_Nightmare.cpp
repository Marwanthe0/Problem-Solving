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
int n;
string s;
vector<int> arr;
vector<vector<vector<int>>> dp;
map<char, int> m;
int f(int i, int v, int c) {
  if (i >= n) {
    // cerr << i << " " << v << " " << c << endl;
    if (v >= 3 || c >= 5)
      return dp[i][v][c] = 0;
    else
      return dp[i][v][c] = 1;
  }
  if (dp[i][v][c] != INT_MIN)
    return dp[i][v][c];
  int ans = 0;
  if (v >= 3 || c >= 5)
    return dp[i][v][c] = 0;
  if (m[s[i]] == 1)
    return dp[i][v][c] = f(i + 1, v + 1, 0);
  else if (m[s[i]] == 2)
    return dp[i][v][c] = f(i + 1, 0, c + 1);
  else {
    int a = f(i + 1, v + 1, 0), b = f(i + 1, 0, c + 1);
    // cerr << i << " " << a << " " << b << " " << v + 1 << " " << c + 1 <<
    // endl;
    if (a == -1 || b == -1)
      return dp[i][v][c] = -1;
    if ((a == 0 && b == 1) || (b == 0 && a == 1))
      return dp[i][v][c] = -1;
    else
      return dp[i][v][c] = a;
  }
}
void marwan(int cs) {
  cout << "Case " << cs << ": ";
  cin >> s;
  n = s.size();
  dp.assign(n + 1, vector<vector<int>>(6, vector<int>(8, INT_MIN)));
  for (auto ch : "AEIOU")
    m[ch] = 1;
  for (char c = 'A'; c <= 'Z'; c++)
    if (!m.count(c))
      m[c] = 2;
  // 1 = vowel, 2 = cons, 0 = ?
  //   for (auto vl : arr)
  //     cerr << vl << " ";
  //   cerr << endl;
  int ans = f(0, 0, 0);
  if (ans == -1)
    cout << "MIXED" << endl;
  else if (ans == 0)
    cout << "BAD" << endl;
  else
    cout << "GOOD" << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}