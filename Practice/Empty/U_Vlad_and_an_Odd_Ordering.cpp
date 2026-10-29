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
void marwan(int cs) {
  int n, k;
  cin >> n >> k;
  int x = (n + 1) / 2, cnt = 0;
  while ((cnt + x < k)) {
    cnt += x;
    x /= 2;
  }
  cout << x << " " << cnt << endl;
  return;
  //   multiset<int> ms;
  //   int x = 1;
  //   while (ms.size() < n && x <= n) {
  //     int cnt = 0;
  //     for (int i = 1; i * x <= n; i += 2) {
  //       if (!ms.count(i * x)) {
  //         cout << i * x << " ";
  //         ms.insert(i * x);
  //         cnt++;
  //       }
  //     }
  //     if (cnt) {
  //       cout << endl;
  //       cout << cnt << endl;
  //     }
  //     x++;
  //   }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}