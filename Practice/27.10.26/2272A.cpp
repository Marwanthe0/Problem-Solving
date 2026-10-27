#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int f(vector<int> &v, int k) {
  int n = v.size();
  vector<int> vis(n + 1, 0);
  int mex = 0;
  vector<int> ans;
  for (int i = 0; i < v.size(); i++) {
    vis[v[i]]++;
    while (vis[mex])
      mex++;
    ans.push_back(mex);
  }
  sort(all(ans));
  reverse(all(ans));
  return ans[k - 1];
}
void marwan(int cs) {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int mx = f(v, k);
  pair<int, int> ans = {-1, -1};
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      swap(v[i], v[j]);
      int x = f(v, k);
      if (x > mx)
        ans = {i + 1, j + 1}, mx = x;
      swap(v[i], v[j]);
    }
  }
  if (ans.first == -1)
    cout << -1 << endl;
  else
    cout << ans.first << " " << ans.second << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}