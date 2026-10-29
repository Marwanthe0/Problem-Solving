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
  int n;
  cin >> n;
  vector<int> pos(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  for (int i = 2; i <= n; i++) {
    if (pos[i] - pos[i - 1] == 1 || pos[i] < pos[i - 1])
      continue;
    else {
      no;
      return;
    }
  }
  yes;
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