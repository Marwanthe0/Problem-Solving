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
  int n;
  cin >> n;
  string s;
  cin >> s;
  set<char> st;
  for (auto c : s)
    st.insert(c);
  int cnt = st.size();
  map<char, int> m;
  int l = 0, r = 0, ans = n;
  while (r < n) {
    m[s[r]]++;
    while (m.size() == cnt) {
      ans = min(ans, r - l + 1);
      m[s[l]]--;
      if (m[s[l]] <= 0)
        m.erase(s[l]);
      l++;
    }
    r++;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}