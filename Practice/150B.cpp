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
  int n, m, k;
  cin >> n >> m >> k;
  if (n == 1)
    cout << m << endl;
  else if (n == 2 && k == 1)
    cout << (m * 1ll * m) % M << endl;
  else if (k < n)
    cout << m << endl;
  else if (k == n)
    cout << (binexp(m, (n + 1) / 2)) % M << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}