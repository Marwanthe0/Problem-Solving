#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define K 1000000009
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
  string s, t;
  cin >> s;
  cin >> t;
  int k, n = s.size();
  vector<int> vis(26, 0);
  cin >> k;
  for (int i = 0; i < 26; i++)
    vis[i] = t[i] - '0';
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    int count = 0;
    int p1 = 31, p2 = 27, p1val = 1, p2val = 1, tans1 = 0, tans2 = 0;
    for (int j = i; j < n; j++) {
      count += !vis[s[j] - 'a'];
      if (count > k)
        break;
      tans1 = (tans1 + p1val * 1ll * (s[j] - 'a' + 1) % M) % M;
      tans2 = (tans2 + p2val * 1ll * (s[j] - 'a' + 1) % K) % K;
      p1val = (p1val * 1ll * p1) % M;
      p2val = (p2val * 1ll * p2) % K;
      ans.push_back({tans1, tans2});
    }
  }
  make_unique(ans);
  cout << ans.size() << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}