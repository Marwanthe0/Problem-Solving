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
  int m, n = s.size();
  s = '0' + s;
  cin >> m;
  vector<int> dif(n + 2, 0);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    dif[x]++, dif[n - x + 2]--;
  }
  for (int i = 1; i <= n; i++)
    dif[i] += dif[i - 1];
  for (int i = 1; i <= n; i++) {
    // cout << dif[i] << " ";
    if (dif[i] & 1)
      cout << s[n - i + 1];
    else
      cout << s[i];
  }
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}