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
  int q;
  cin >> q;
  string s, t;
  cin >> s;
  cin >> t;
  int n = s.size(), m = t.size();
  set<int> st;
  for (int i = 0; i < n; i++) {
    int ti = i, flag = false, j = 0;
    for (; j < m; j++) {
      if (i < n && s[i] == t[j]) {
        i++;
      } else
        break;
    }
    if (j == m) {
      st.insert(ti);
      flag = true;
      i--;
    }
    i = ti;
  }
  //   for (auto vl : st)
  //     cerr << vl << " ";
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    auto it = st.lower_bound(l);
    if (it == st.end()) {
      no;
    } else if (*it + m - 1 <= r) {
      yes;
    } else
      no;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}