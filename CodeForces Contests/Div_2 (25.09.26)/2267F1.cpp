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
  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  multiset<int> ms;
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  vector<int> qs(q), ans;
  ans.push_back(v.back() - v.front());
  for (auto &vl : qs)
    cin >> vl;
  int mx = *max_element(all(qs));
  vector<int> t = v;
  for (int x = 0; x < mx; x++) {
    vector<int> tt;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        tt.push_back(t[i] ^ t[j]);
      }
    }
    sort(all(tt));
    t.clear();
    for (int i = 0; i < n; i++)
      t.push_back(tt[i]);
    int rng = t.back() - t.front();
    if (!rng)
      break;
    ans.push_back(rng);
  }
  for (auto vl : qs) {
    if (vl >= ans.size())
      cout << 0 << endl;
    else
      cout << ans[vl] << endl;
  }
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