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
  int a, b;
  cin >> a >> b;
  if (b > 2 * a + 2 || b < a - 1) {
    minus;
    return;
  }
  string ans;
  for (int i = 0; i < min(a, b); i++) {
    ans.push_back('1');
    ans.push_back('0');
  }
  if (a > b) {
    cout << '0' << ans << endl;
    return;
  }
  string s;
  int count = 0;
  b -= a;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (count < b && ans[i] == '1') {
      cout << '1';
      count++;
    }
  }
  while (count < b) {
    count++;
    cout << '1';
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}