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
  int n, ans = 1, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  int cnt = 0;
  map<int, int> m;
  for (auto vl : v) {
    if (vl % k)
      m[vl]++;
    else if (!m.count(vl / k))
      m[vl]++;
  }
  cout << m.size() << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}