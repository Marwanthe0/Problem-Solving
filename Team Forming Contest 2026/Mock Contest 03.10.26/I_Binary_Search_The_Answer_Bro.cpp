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
vector<vector<char>> v;
void marwan(int cs) {
  cin >> n;
  v.assign(n + 1, vector<char>(n + 1, '.'));
  vector<pair<int, int>> ch, d;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      v[i][j] = s[j];
      if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C')
        ch.push_back({i, j});
      else if (s[i] == 'X')
        d.push_back({i, j});
    }
  }
  vector<map<pair<int,int>,string>> chs, ds;
  for (auto [i, j] : ch) {
    map<pair<int, int>, string> m;
    
  }
  int ans = INT_MAX;
  auto f = [&](int i, int j, int l, int r) -> int {

  };
  for (auto [i, j] : ch) {
    for (auto [u, v] : d) {
      ans = min(ans, f(i, j, u, v));
    }
  }
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