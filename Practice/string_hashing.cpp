#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define K 1000000011
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
pair<int, int> hashh(string &s) {
  int n = s.size(), re = 0, base1 = 27, base2 = 31, re2 = 0;
  reverse(all(s));
  for (int i = 0; i < n; i++) {
    re = (re + ((s[i] - 'a' + 1) * base1) % M) % M;
    re2 = (re2 + ((s[i] - 'a' + 1) * base2) % K) % K;
    base1 *= 27;
    base1 %= M;
    base2 *= 31;
    base2 %= K;
  }
  reverse(all(s));
  return {re, re2};
}
void marwan() {
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v[i] = hashh(s);
  }
  for (auto vl : v)
    cout << vl.first << " " << vl.second << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}