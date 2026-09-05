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
  int n, k;
  cin >> n >> k;
  vector<int> v(n), dif;
  for (auto &vl : v)
    cin >> vl;
  for (int i = 1; i < n; i++)
    dif.push_back((v[i] - v[i - 1]) - k);
  for (auto vl : dif)
    cout << vl << " ";
  cout << endl;
  cout << 0 << " ";
  for (int i = 1; i + 1 < n; i++) {
    int x = v[i - 1], y = v[i + 1];
    if (y - x <= k) {
      cout << 0 << " ";
    } else {
      int sum = 0, cur = k + x;
      for (int j = i + 1; j < n; j++) {
        if (v[j] > cur)
          sum += max(0ll, v[j] - cur), cur += k;
        else
          break;
        if (abs(dif[j - 1]) < )
      }
      cout << sum << " ";
    }
  }
  cout << 0 << endl;
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