#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n, m;
  cin >> n >> m;
  set<char> st;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    st.insert(s[0]);
  }
  vector<string> t(m);
  for (auto &vl : t)
    cin >> vl;
  for (int i = 0; i < m; i++) {
    string s = t[i];
    for (auto &c : s) {
      if (c >= 'A' && c <= 'Z') {
        c = (c - 'A') + 'a';
        if (!st.count(c)) {
          no;
          return;
        }
      }
    }
    st.insert(s[0]);
  }
  yes;
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