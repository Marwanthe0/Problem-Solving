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
  int n;
  cin >> n;
  vector<int> v(n), pf(n, 0);
  for (auto &vl : v)
    cin >> vl;
  for (int i = 1; i + 1 < n; i++) {
    if (v[i] >= v[i - 1] && v[i] >= v[i + 1]) {
      cout << i << " " << i + 2 << endl;
      return;
    }
  }
  stack<int> st;
  for (int i = 0; i < n; i++) {
    while (st.size() && v[st.top()] < v[i]) {
      st.pop();
    }
    if (st.size() && v[st.top()] == v[i]) {
      cout << v[st.top()] + 1 << " " << i + 1 << endl;
      return;
    }
    st.push(i);
  }
  cout << -1 << endl;
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