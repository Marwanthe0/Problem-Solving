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
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  reverse(all(v));
  int l = 1, r = n, ans = n;
  auto ok = [&](int mid) {
    vector<vector<int>> t(mid);
    for (int i = 0; i < mid; i++)
      t[i].push_back(v[i]);
    for (int i = mid; i < n; i++) {
      bool f1 = false;
      for (auto &vc : t) {
        bool flag = true;
        for (int j = 0; j < vc.size(); j++) {
          int elem = (vc.size() - j) - 1;
          if (elem >= vc[j]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          vc.push_back(v[i]);
          f1 = true;
          break;
        }
      }
      if (!f1)
        return false;
    }
    return true;
  };
  while (l <= r) {
    int mid = l + (r - l) / 2;
    bool kk = ok(mid);
    cerr << kk << " " << mid << endl;
    if (kk) {
      r = mid - 1, ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}