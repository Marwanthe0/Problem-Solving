#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "yes" << endl
#define no cout << "no" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n;
  cin >> n;
  int z = 0, mo = 0, po = 0, el = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0)
      z++;
    else if (x == 1)
      po++;
    else if (x == -1)
      mo++;
    else
      el++;
  }
  if (el && mo) {
    no;
    return;
  }
  if (el > 1) {
    no;
    return;
  }
  if (mo > 1 && po == 0) {
    no;
    return;
  }
  yes;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}