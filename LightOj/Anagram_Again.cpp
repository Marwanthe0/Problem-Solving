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
void marwan(int cs) {
  int n;
  cin >> n;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    sort(all(s));
    v.push_back(s);
  }
  int q;
  cin >> q;
  cout << "Case " << cs << ":" << endl;
  while (q--) {
    string s;
    cin >> s;
    sort(all(s));
    int ans = 0;
    for (auto vl : v) {
      //   cerr << vl << " " << s << endl;
      int i = 0, j = 0, sz1 = s.size(), sz2 = vl.size();
      while (i < sz1 && j < sz2) {
        if (s[i] == vl[j])
          j++;
        i++;
      }
      ans += (j == sz2);
    }
    cout << ans << endl;
  }
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