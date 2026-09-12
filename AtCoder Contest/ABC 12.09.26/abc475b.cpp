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
  vector<int> v(n);
  int a = 0, b = 0, c = 0;
  for (auto &vl : v) {
    cin >> vl;
    vl %= 1000;
    string t = to_string(vl);
    while (t.size() < 3)
      t = '0' + t;
    int x = 0, y = 0, z = 0;
    x += (t[0] - '0');
    if (t[1] - '0' || t[2] - '0')
      x++;
    y += t[1] - '0';
    if (t[2] - '0')
      y++;
    z += t[2] - '0';
    // cerr << x << " " << y << " " << z << endl;
    if (x)
      a += 10 - x;
    if (y)
      b += 10 - y;
    if (z)
      c += 10 - z;
  }
  cout << c << " " << b << " " << a << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}