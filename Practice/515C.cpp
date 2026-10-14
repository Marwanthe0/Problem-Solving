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
  string s;
  cin >> s;
  string ans;
  for (auto c : s) {
    switch (c) {
    case '1':
      break;
    case '2':
      ans.push_back('2');
      break;
    case '3':
      ans.push_back('3');
      break;
    case '4':
      ans.push_back('2');
      ans.push_back('2');
      ans.push_back('3');
      break;
    case '5':
      ans.push_back('5');
      break;
    case '6':
      ans.push_back('5');
      ans.push_back('3');
      break;
    case '7':
      ans.push_back('7');
      break;
    case '8':
      ans.push_back('7');
      ans.push_back('2');
      ans.push_back('2');
      ans.push_back('2');
      break;
    case '9':
      // 2*3*4*5*6*7*8*9 = 7!*2!*2!**3*3
      ans.push_back('7');
      ans.push_back('2');
      ans.push_back('3');
      ans.push_back('3');
      break;
    }
  }
  sort(all(ans));
  reverse(all(ans));
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}