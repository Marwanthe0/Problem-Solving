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
  int x = 1, prevsum = 0, ans = 0;
  for (int i = 1; i < n; i++) {

    if (v[i] + prevsum < v[i - 1]) {
      while (v[i] + prevsum < v[i - 1]) {
        prevsum += (1ll << x);
        x++;
      }
      v[i] = v[i - 1];
    }
    // cerr << i << " " << v[i] << " " << x << endl;
  }
  //   cerr << endl;
  cout << x << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--)
    marwan();
  return 0;
}