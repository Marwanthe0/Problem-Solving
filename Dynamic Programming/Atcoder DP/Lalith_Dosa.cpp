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
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x -= (i + 1);
    if (x < 0)
      continue;
    auto it = upper_bound(all(a), x);
    if (it == a.end())
      a.push_back(x);
    else
      *it = x;
  }
  cout << n - a.size() << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}