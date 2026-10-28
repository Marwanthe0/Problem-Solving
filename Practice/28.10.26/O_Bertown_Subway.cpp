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
  vector<int> v(n + 1, 0), vis(n + 1, 0);
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  vector<int> ans;
  int ans1 = 0ll;
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    int count = 0, cur = i;
    while (!vis[cur]) {
      vis[cur] = 1;
      cur = v[cur];
      count++;
    }
    ans.push_back(count);
    ans1 += count * 1ll * count;
  }
  sort(all(ans));
  reverse(all(ans));
  int uttor = 0ll;
  for (int i = 2; i < ans.size(); i++) {
    uttor += ans[i] * 1ll * ans[i];
  }
  if (ans.size() <= 1) {
    cout << ans[0] * 1ll * ans[0] << endl;
    return;
  }
  int last = ans[0] + ans[1];
  uttor += (last * 1ll * last);
  cout << max(uttor, ans1) << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}