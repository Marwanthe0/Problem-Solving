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
int binexp(int a, int b) {
  int ans = 1ll;
  while (b) {
    if (b & 1)
      ans = (ans * 1ll * a) % M;
    a = (a * 1ll * a) % M;
    b >>= 1;
  }
  return ans % M;
}
void marwan() {
  int a, b;
  cin >> a >> b;
  int x = binexp(a, b), y = binexp(b, a);
  cout << x + y << endl;
  int z = x + y;
  cerr << __gcd(abs(a - b), ) << endl;
  map<int, int> m;
  for (int i = 2; i * i <= z; i++) {
    while (z % i == 0) {
      z /= i;
      m[i]++;
    }
  }
  if (z > 1)
    m[z]++;
  for (auto [x, y] : m)
    cout << x << " " << y << endl;
  cout << endl;
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