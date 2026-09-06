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
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &vl : a)
    cin >> vl;
  for (auto &vl : b)
    cin >> vl;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      yes;
      for (int j = 0; j < n; j++) {
        if (i == j)
          cout << 1000000000000000000 << " ";
        else
          cout << 1 << " ";
      }
      return;
    }
  }
  no;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}