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
  int n, q;
  cin >> n >> q;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  vector<int> dif(n + 2, 0);
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    dif[x]++;
    dif[y + 1]--;
  }
  for (int i = 1; i <= n; i++) {
    dif[i] += dif[i - 1];
  }
  sort(all(dif));
  reverse(all(dif));
  sort(all(v));
  reverse(all(v));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += v[i] * dif[i];
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}