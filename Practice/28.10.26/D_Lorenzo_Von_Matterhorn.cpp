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
int n;
map<int, int> m;
void f1(int u, int v, int w) {
  while (__lg(u) != __lg(v)) {
    if (__lg(u) < __lg(v))
      swap(u, v);
    m[u] += w;
    u >>= 1;
  }
  while (u != v) {
    m[u] += w;
    m[v] += w;
    u >>= 1, v >>= 1;
  }
}
int f2(int u, int v) {
  int sum = 0;
  while (__lg(u) != __lg(v)) {
    if (__lg(u) < __lg(v))
      swap(u, v);
    if (m.count(u))
      sum += m[u];
    u >>= 1;
  }
  while (u != v) {
    if (m.count(u))
      sum += m[u];
    if (m.count(v))
      sum += m[v];
    u >>= 1, v >>= 1;
  }
  return sum;
}
void marwan() {
  cin >> n;
  while (n--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, v, w;
      cin >> u >> v >> w;
      f1(u, v, w);
    } else {
      int u, v;
      cin >> u >> v;
      cout << f2(u, v) << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}