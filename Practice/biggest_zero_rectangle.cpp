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
  vector<vector<int>> v(n, vector<int>(m + 2, -1));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++)
      v[i][j] = (s[j - 1] - '0');
  }
  for (int j = 1; j <= m; j++) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (v[i][j])
        count++, v[i][j] = count;
      else
        v[i][j] = count = 0;
    }
  }
  //   for (int i = 0; i < v.size(); i++) {
  //     for (int j = 0; j < v[i].size(); j++)
  //       cerr << v[i][j];
  //     cerr << endl;
  //   }
  //   cerr << endl;
  //   return;
  int ans = 0;
  auto f = [&](vector<int> &a) -> int {
    stack<int> st;
    vector<int> pf(m + 1), sf(m + 1);
    st.push(0);
    for (int j = 1; j <= m; j++) {
      while (st.size() && a[st.top()] >= a[j])
        st.pop();
      pf[j] = j - st.top();
      st.push(j);
    }
    while (st.size())
      st.pop();
    st.push(m + 1);
    for (int j = m; j >= 1; j--) {
      while (st.size() && a[st.top()] >= a[j])
        st.pop();
      sf[j] = st.top() - j;
      st.push(j);
    }
    int mx = 0;
    for (int i = 1; i <= m; i++) {
      //   cerr << pf[i] << " ";
      mx = max(mx, a[i] * (pf[i] + sf[i] - 1));
    }
    return mx;
    cerr << endl;
    for (int i = 1; i <= m; i++) {
      cerr << sf[i] << " ";
      mx = max(mx, a[i] * (pf[i] + sf[i] - 1));
    }
    cerr << endl;
    for (int i = 1; i <= m; i++)
      cerr << a[i] * (pf[i] + sf[i] - 1) << " ";
    cerr << endl;
    return mx;
  };
  for (int i = 0; i < n; i++) {
    cerr << i << endl;
    ans = max(ans, f(v[i]));
  }
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