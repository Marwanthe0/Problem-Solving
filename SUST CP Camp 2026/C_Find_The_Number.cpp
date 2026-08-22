#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 120
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
vector<int> ans;
void pre() {
  map<int, int> m;
  for (int x = 2; x <= N; x++) {
    int val = x;
    for (int i = 2; i <= x; i++) {
      while (x % i == 0) {
        m[i]++;
        x /= i;
      }
    }
    if (x > 1)
      m[x]++;
    x = val;
    int tans = 1ll;
    for (auto [vl, occ] : m) {
      //   cout << vl << " " << occ << endl;
      tans *= (occ + 1);
    }
    // cout << endl;
    ans.push_back(tans);
    // cout << tans << endl;
  }
  //   cout << endl;
}
void marwan() {
  int n;
  cin >> n;
  if (n == 0) {
    cout << "nai" << endl;
    return;
  }
  auto it = lower_bound(all(ans), n);
  if (it == ans.end() || *it != n) {
    cout << "nai" << endl;
  } else
    cout << it - ans.begin() + 1 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ans.push_back(1);
  pre();
  //   return 0;
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}