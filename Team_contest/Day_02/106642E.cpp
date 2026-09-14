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
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int one = count(all(v), 1), zr = count(all(v), 0), two = count(all(v), 2),
      sum = accumulate(all(v), 0ll);
  if (zr == 0 || two == 0 || sum != n) {
    no;
    return;
  }
  if (two > (n / 2) || zr > (n / 2) || (one & 1) != ((n - 2) & 1)) {
    no;
    return;
  }
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i - 1]) {
      if (v[i] == 1)
        continue;
      no;
      return;
    }
    if (i + 1 < n) {
      if (v[i] == 1) {
        if (v[i - 1] == 2 && v[i + 1] == 2) {
          no;
          return;
        }
      }
    }
  }
  if (v[0] == 1 && v[1] == 2 && v.back() == 2) {
    no;
    return;
  }
  if (v.back() == 1 && v[n - 2] == 2 && v.front() == 2) {
    no;
    return;
  }
  if (v[n - 1] == v[0]) {
    if (v[0] != 1) {
      no;
      return;
    }
  }
  yes;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}