#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
void marwan(int cs) {
  int l, h, k;
  cin >> l >> h >> k;
  int i = 1, j = 1e9, ans = -1;
  while (i <= j) {
    int mid = i + (j - i) / 2;
    if ((l / mid) * (h / mid) >= k) {
      ans = mid, i = mid + 1;
    } else
      j = mid - 1;
  }
  cout << "Case " << cs << ": ";
  cout << ans << endl;
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