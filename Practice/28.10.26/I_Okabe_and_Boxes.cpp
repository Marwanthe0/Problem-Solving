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
  vector<int> v;
  stack<int> st;
  int cnt = 1, ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    string op;
    cin >> op;
    if (op == "add") {
      int val;
      cin >> val;
      st.push(val);
    } else {
      if (st.size()) {
        if (st.top() == cnt)
          st.pop();
        else {
          ans++;
          while (st.size())
            st.pop();
        }
      }
      cnt++;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}