#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
void marwan() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int zeros = count(all(s), '0');
  if (k == 1) {
    cout << zeros << endl;
    return;
  }
  if (n < 3) {
    if (count(all(s), '0') == 2) {
      cout<<1<<endl;return;
    }
  }
  int l = 0, r = 0;
  int zr = 0, one = 0, ans = 0;
  while (r < n) {
    zr += s[r] == '0';
    one += s[r] == '1';
    if (r - l + 1 == 3) {
      if (zr == 3) {
        s[r] = s[r - 1] = '1';
        zr -= 2;
        one += 2;
        ans += 2;
      } else if (zr == 2) {
        if (s[r] == '0')
          s[r] = '1';
        else
          s[r - 1] = '1';
        zr--,one++;
        ans++;
      }
      zr -= s[l] == '0';
      one -= s[l] == '1';
      l++;
    }
    r++;
  }
//   cerr << s << endl;
  cout << ans << endl;
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