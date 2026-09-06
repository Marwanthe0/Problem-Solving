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
  int n, k;
  cin >> n >> k;
  vector<int> v(n, 0), t(k), vis(n + 1, 0), tans;
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (auto &vl : t) {
    cin >> vl;
    vis[vl]++;
  }
  //   v.pop_front();
  for (auto vl : v) {
    if (!vis[vl])
      cout << vl << " ";
  }
  for (int i = k - 1; i >= 0; i--) {
    if (vis[t[i]]) {
      tans.push_back(t[i]);
      vis[t[i]] = 0;
    }
  }
  reverse(all(tans));
  for (auto vl : tans)
    cout << vl << " ";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}