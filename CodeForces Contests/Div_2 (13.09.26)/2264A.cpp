#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> t;
  for (int i = 1; i <= n; i++) {
    if (v[i - 1] != i)
      t.push_back(v[i - 1]);
  }
  reverse(all(t));
  if (is_sorted(all(t)))
    yes;
  else
    no;
  //   for (auto vl : t)
  //     cout << vl << " ";
  //   cout << endl;
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