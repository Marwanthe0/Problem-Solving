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
  vector<int> v(n), pf(n, 0), sf(n + 1, 0);
  for (auto &vl : v)
    cin >> vl;
  if (is_sorted(all(v))) {
    yes;
    return;
  }
  pf.front() = sf.back() = sf[n - 1] = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] >= v[i - 1])
      pf[i] = 1;
    else
      break;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (v[i] <= v[i + 1])
      sf[i] = 1;
    else
      break;
  }
  //   for (int i = 0; i < n; i++)
  //     cout << pf[i] << " ";
  //   cout << endl;
  //   for (int i = 0; i < n; i++)
  //     cout << sf[i] << " ";
  //   cout << endl;
  //   cout << endl;
  //   return;
  int l = 0, r = 0;
  multiset<int> ms;
  while (r < n) {
    ms.insert(v[r]);
    if (r - l + 1 == k) {
      if ((l == 0 || pf[l - 1]) && sf[r + 1]) {
        int mn = *ms.begin(), mx = *(--ms.end());
        if ((mn >= v[l - 1] || l == 0) && (mx <= v[r + 1] || r == n - 1)) {
          yes;
          return;
        }
      }
      ms.erase(ms.find(v[l]));
      l++;
    }
    r++;
  }
  no;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}