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
  if (n == 1) {
    cout << 1 << endl << 0 << endl;
    return;
  }
  map<int, int> m;
  int count = 0;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      n /= i;
      count++;
      m[i]++;
    }
  }
  if (n > 1) {
    count++;
    m[n]++;
  }
  if (count == 2)
    cout << 2 << endl;
  else {
    cout << 1 << endl;
    if (count == 1)
      cout << 0 << endl;
    else {
      int x = m.begin()->first, y = (--m.end())->first;
      cout << x * y << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}