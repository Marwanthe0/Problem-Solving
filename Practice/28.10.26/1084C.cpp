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
  int ans = 1ll, cnt = 1;
  for (auto c : s) {
    if (c == 'a')
      cnt++;
    else if (c == 'b') {
      ans = (ans * 1ll * cnt) % M;
      cnt = 1ll;
    }
  }
  ans = ans * cnt % M;
  cout << ans - 1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}