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
void f(int n) {
  string s;
  for (char i = '1', j = 1; j <= n; i++, j++)
    s.push_back(i);
//   cout << s << endl;
  map<int, int> m;
  do {
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (s[i] < s[j])
          count++;
      }
    }
    m[count]++;
  } while (next_permutation(all(s)));
  for (auto [x, y] : m)
    cout << y << " ";
  cout << endl;
}
void marwan() {
  for (int i = 1; i <= 10; i++) {
    f(i);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}