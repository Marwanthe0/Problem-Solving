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
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    m[x]++;
  }
  vector<int> v;
  for (auto [x, y] : m)
    v.push_back(y);
  sort(all(v));
  int mx = v.back();
  int ans = 0;
  while (v.size() && v.back() + 1 >= mx) {
    ans++, v.pop_back();
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}