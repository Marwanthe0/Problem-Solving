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
  int n;
  cin >> n;
  vector<string> v(2);
  cin >> v[0];
  cin >> v[1];
  int a = 0, b = 0, e1 = 0, e2 = 0;
  int cnt1 = 1, cnt2 = 1;
  for (int i = 0; i < n; i++) {
    if (v[0][i] == v[1][i])
      continue;
    if (v[0][i] == 'f')
      a++;
  }
  e1 += cnt1 / 2;
  e2 += cnt2 / 2;
  e1 *= 2;
  e2 *= 2;
  cerr << a << " " << e1 << " " << b << " " << e2 << endl;
  int l1 = a - e1, l2 = b - e2;
  if (l1 > b) {
    cout << l1 - b << endl;
  } else if (l2 > a)
    cout << l2 - a << endl;
  else
    cout << 0 << endl;
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