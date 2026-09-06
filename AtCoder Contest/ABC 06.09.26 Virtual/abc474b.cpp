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
  vector<int> vis(n + 1, 0);
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  int k = 1;
  for (int i = 1; i <= n; i++) {
    int x = v[i - 1];
    vis[x] = 1;
    if (i % 10 == 0 || i == n) {
      for (int j = k; j <= min(n, k + 9); j++)
        if (!vis[j]) {
          //   cerr << i << " " << j << endl;
          no;
          return;
        } else
          vis[j] = 0;
      k += 10;
    }
  }
  yes;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}