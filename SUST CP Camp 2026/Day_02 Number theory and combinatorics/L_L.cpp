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
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int l = 2, r = *max_element(all(v)), ans = 1;
  auto ok = [&](int mid) {
    vector<pair<int, int>> tt;
    int asum = 0ll, bsum = 0ll;
    for (auto vl : v) {
      int tx = mid - (vl % mid);
      if (tx == mid)
        tx = 0;
      if (tx) {
        tt.push_back({vl % mid, tx});
        asum += vl % mid, bsum += tx;
      }
    }
    sort(all(tt));
    int sm = 0, mn = INT_MAX;
    for (int i = 0; i < (int)(tt.size()); i++) {
      //   cerr << tt[i].first << " " << tt[i].second << endl;
      if (sm == bsum) {
        mn = min(mn, sm);
      }
      sm += tt[i].first;
      bsum -= tt[i].second;
      if (sm == bsum)
        mn = min(mn, sm);
    }
    sm = 0;
    for (int i = 0; i < (int)(tt.size()); i++) {
      if (sm == asum) {
        mn = min(mn, sm);
      }
      sm += tt[i].second;
      asum -= tt[i].first;
      if (sm == asum) {
        mn = min(mn, sm);
      }
    }
    return mn <= k;
  };
  int mx = *max_element(all(v));
  mx = max(mx, min(mx + k, mx * n));
  for (int i = mx; i >= 2; i--) {
    if (ok(i)) {
      cout << i << endl;
      return;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}