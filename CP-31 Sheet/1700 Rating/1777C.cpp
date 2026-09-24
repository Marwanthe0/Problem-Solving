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
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  unordered_set<int> st;
  for (auto &vl : v) {
    cin >> vl;
    st.insert(vl);
  }
  make_unique(v);
  n = v.size();
  vector<int> mp(m + 1, 0);
  int l = 0, r = 0, ans = 1e17, count = 0;
  while (r < n) {
    int x = v[r];
    for (int d = 1; d * d <= x; d++) {
      if (x % d == 0) {
        if (d <= m) {
          if (mp[d] == 0)
            count++;
          mp[d]++;
        }
        if (x / d != d) {
          if (x / d <= m) {
            if (mp[x / d] == 0)
              count++;
            mp[x / d]++;
          }
        }
      }
    }
    while (l <= r && count == m) {
      ans = min(ans, v[r] - v[l]);
      int y = v[l];
      for (int d = 1; d * d <= y; d++) {
        if (y % d == 0) {
          if (d <= m) {
            if (mp[d] == 1)
              count--;
            mp[d]--;
          }
          if (y / d != d) {
            if (y / d <= m) {
              if (mp[y / d] == 1)
                count--;
              mp[y / d]--;
            }
          }
        }
      }
      l++;
    }
    r++;
  }
  cout << (ans == 1e17 ? -1 : ans) << endl;
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