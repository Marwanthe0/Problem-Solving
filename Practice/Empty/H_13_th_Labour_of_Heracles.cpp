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
int n;
// vector<vector<int>> g;
vector<int> a;
void marwan(int cs) {
  cin >> n;
  a.assign(n, 0);
  int sum = 0;
  for (auto &vl : a) {
    cin >> vl;
    sum += vl;
  }
  vector<int> t;
  map<int, int> m;
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (m.count(u))
      t.push_back(a[u]);
    if (m.count(v))
      t.push_back(a[v]);
    m[u]++, m[v]++;
  }
  sort(all(t));
  reverse(all(t));
  cout << sum << " ";
  for (int i = 0; i + 2 < n; i++) {
    sum += t[i];
    cout << sum << " ";
  }
  cout << endl;
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