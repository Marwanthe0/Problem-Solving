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
void marwan(int cs) {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  int x1 = 0, x2 = 0;
  for (int i = 0; i < n; i++) {
    if (!m.count(i))
      break;
    int xk = (m[i] + 1) / 2;
    int yk = m[i] - xk;
    if (xk >= k && x1 == i)
      x1++;
    if (yk >= k && x2 == i)
      x2++;
  }
  if (x1 == x2)
    no;
  else
    yes;
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