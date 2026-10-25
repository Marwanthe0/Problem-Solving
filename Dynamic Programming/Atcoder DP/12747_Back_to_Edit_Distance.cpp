#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int n;
vector<int> a, b;
int f(int i, int j) {
  if (i == n)
    return n - (j);
  if (j == n)
    return n - (i);

  int ans = 1e9;
  if (a[i] == b[j])

    ans = min(ans, f(i + 1, j + 1));
  ans = min(ans, 1 + f(i + 1, j));
  ans = min(ans, 1 + f(i, j + 1));
  return ans;
}
void marwan(int cs) {
  cin >> n;
  a.assign(n, 0);
  b.assign(n, 0);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;
  cout << f(0, 0) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ": ";
    marwan(i);
  }
  return 0;
}