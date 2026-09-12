#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 10000005
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
vector<int> primes, isprime(N + 1, 0);
void pre() {
  for (int i = 2; i * i <= N; i++) {
    if (!isprime[i])
      for (int j = i * i; j <= N; j += i)
        isprime[j] = 1;
  }
  for (int i = 2; i <= N; i++) {
    if (!isprime[i])
      primes.push_back(i);
  }
}
void marwan() {
  string s;
  cin >> s;
  int n = s.size();
  map<int, vector<int>> m;
  int chars = 0;
  for (int i = 0; i < n; i++) {
    if (m.count(s[i] - '0') == 0)
      chars++;
    m[s[i] - '0'].push_back(i);
  }
  for (auto vl : primes) {
    int ln = to_string(vl).size();
    if (ln < n)
      continue;
    else if (ln > n)
      break;
    else {
      string t = to_string(vl);
      vector<int> vis(n, 0);
      set<char> st(all(t));
      if (st.size() != chars) {
        continue;
      }
      //   cerr << vl << endl;
      bool flag = true;
      for (auto [x, y] : m) {
        char c = t[y[0]];
        for (auto val : y) {
          if (t[val] != c) {
            flag = false;
            vis[val] = 1;
          }
        }
        if (!flag) {
          break;
        }
      }
      if (flag) {
        cout << t << endl;
        return;
      }
    }
  }
  minus;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  marwan();
  return 0;
}