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
  string a, b;
  cin >> a >> b;
  int n = a.size(), m = b.size();
  vector<int> d1, d2;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      d1.push_back(i);
      d1.push_back(n / i);
    }
  }
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      d2.push_back(i);
      d2.push_back(m / i);
    }
  }
  make_unique(d1);
  make_unique(d2);
  //   for (auto vl : d1)
  //     cerr << vl << " ";
  //   cerr << endl;
  //   for (auto vl : d2)
  //     cerr << vl << " ";
  //   cerr << endl;
  map<string, int> m1;
  for (auto d : d1) {
    bool flag = true;
    // cerr << d << "::" << endl;
    for (int i = 0; i < d; i++) {
      for (int j = i; j < n; j += d) {
        if (a[j] != a[i]) {
          //   cerr << i << " " << j << endl;
          flag = false;
          break;
        }
      }
      if (!flag)
        break;
    }
    if (flag) {
      string tmp;
      for (int i = 0; i < d; i++) {
        tmp.push_back(a[i]);
      }
      //   cerr << tmp << endl;
      m1[tmp]++;
    }
  }
  //   cerr << endl;
  for (auto d : d2) {
    bool flag = true;
    for (int i = 0; i < d; i++) {
      for (int j = i; j < m; j += d) {
        if (b[j] != b[i]) {
          flag = false;
          break;
        }
      }
      if (!flag)
        break;
    }
    if (flag) {
      string tmp;
      for (int i = 0; i < d; i++) {
        tmp.push_back(b[i]);
      }
      //   cerr << tmp << endl;
      m1[tmp]++;
    }
  }
  int ans = 0;
  for (auto [x, y] : m1) {
    if (y < 2)
      continue;
    // cerr << x << endl;
    ans++;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  marwan();
  return 0;
}