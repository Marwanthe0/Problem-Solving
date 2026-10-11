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
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  int ans = 1ll;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int j = 0; j < m; j++) {
    set<char> st;
    for (int i = 0; i < n; i++) {
      st.insert(v[i][j]);
    }
    ans = (ans * 1ll * ((int)(st.size()))) % M;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}