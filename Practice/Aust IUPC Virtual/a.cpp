#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
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
  int n, p, q;
  cin >> n >> p >> q;
  cpp_int sum = 0;
  while (n--) {
    cpp_int x;
    cin >> x;
    sum += x;
  }
  string s = string(sum);
  cpp_int sum2 = 0;
  for (int i = p - 1; i < q; i++) {
    cout << s[i];
    sum2 += cpp_int(s[i] - '0');
    sum2 *= cpp_int(10);
  }
  cout << endl;
  cout << sum2 % 3 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}