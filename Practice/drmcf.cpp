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
int n, k;
vector<int> a, b;
int f(int i) {
  
}
void marwan() {
  cin >> n >> k;
  a.assign(n, 0), b.assign(n, 0);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;
  int ans = f(0);
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