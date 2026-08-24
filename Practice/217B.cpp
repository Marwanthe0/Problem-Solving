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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n, r;
  cin >> n >> r;
  int best_i = -1, mistakes = INT_MAX;
  for (int i = 1; i <= r; i++) {
    if (__gcd(i, r) != 1)
      continue;
    int mist = 0, count = 0;
    int a = i, b = r;
    while (a && b) {
      if (a >= b) {
        count += a / b;
        if (a % b == 0) {
          mist += (a / b) - 1;
          break;
        } else
          mist += (a / b) - 1;
        a %= b;
      } else {
        count += b / a;
        // mist += (b / a) - 1;
        if (b % a == 0) {
          mist += (b / a >= 2 ? (b / a) - 2 : 0);
          break;
        } else
          mist += (b / a) - 1;
        b %= a;
      }
    }
    if (count == n && mist < mistakes) {
      cerr << i << " " << mist << endl;
      mistakes = mist, best_i = i;
    }
  }
  if (mistakes == INT_MAX) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  string s;
  int a = best_i, b = r;
  while (a && b) {
    if (a >= b) {
      s.push_back('T');
      a -= b;
    } else {
      s.push_back('B');
      b -= a;
    }
  }
  reverse(all(s));
  cerr << best_i << endl;
  if (s[0] == 'B') {
    for (auto &c : s)
      c = (c == 'T' ? 'B' : 'T');
  }
  cout << mistakes << "\n" << s << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}