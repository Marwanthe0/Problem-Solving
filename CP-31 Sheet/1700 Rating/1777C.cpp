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
vector<int> vis(N + 1, -1);
void marwan() {
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  make_unique(v);
  n = v.size();
  for (int i = 0; i < n; i++)
    vis[v[i]] = i;
  int l = 0, r = n - 1;
  int mx = v.back();
  auto ok = [&](int st, int end) -> bool {
    for (int i = 2; i <= m; i++) {
      bool flag = false;
      for (int j = i; j <= mx; j += i) {
        if (st <= vis[j] && vis[j] <= end) {
          flag = true;
        }
      }
      if (!flag) {
        return false;
      }
    }
    return true;
  };
  int ans = n - 1, ans2 = 0;
  bool flag = false;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(0, mid)) {
      r = mid - 1, ans = mid, flag = true;
    } else {
      l = mid + 1;
    }
  }
  if (!flag) {
    for (auto vl : v)
      vis[vl] = -1;
    minus;
    return;
  }
  l = 0, r = ans;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (ok(mid, ans)) {
      l = mid + 1, ans2 = mid;
    } else
      r = mid - 1;
  }
  for (auto vl : v)
    vis[vl] = -1;
  cout << v[ans] - v[ans2] << endl;
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