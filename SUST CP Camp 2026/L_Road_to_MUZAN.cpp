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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  map<char, int> m;
  for (auto c : s) {
    m[c]++;
  }
  int odd = 0, sum = 0;
  for (auto [x, y] : m) {
    sum += y / 2;
    odd += (y & 1);
  }
  cout << "Case " << cs << ":" << endl;
  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    char ac = s[pos - 1];
    // odd->even
    if (m[ac] & 1) {
      m[ac]--;
      odd--;
    } else {
      m[ac]--;
      sum--;
      if (m[ac])
        odd++;
    }
    // odd->even
    if (m[c] & 1) {
      m[c]++;
      odd--;
      sum++;
    } else {
      m[c]++;
      odd++;
    }
    s[pos - 1] = c;
    cout << sum * 2 + (odd > 0) << endl;
  }
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