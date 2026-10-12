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
  string s;
  cin >> s;
  int count = 1, n = s.size();
  vector<pair<int, char>> v;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1])
      count++;
    else {
      v.push_back({count, s[i - 1]});
      count = 1;
    }
  }
  v.push_back({count, s.back()});
  for (int i = 1; i < v.size(); i++) {
    if (v[i].first >= 2 && v[i - 1].first >= 2) {
      v[i - 1].first = 2, v[i].first = 1;
    }
  }
  for (auto &[x, y] : v)
    if (x > 2)
      x = 2;
  for (auto [x, y] : v) {
    for (int i = 0; i < x; i++)
      cout << y;
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}