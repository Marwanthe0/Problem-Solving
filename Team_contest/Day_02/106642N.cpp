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
  string s;
  cin >> s;
  vector<int> v(n, 0), pf(n, 0), sf(n, 0);
  char c;
  cin >> c;
  map<char, int> m;
  m['R'] = 0, m['P'] = 1, m['S'] = 2;
  for (int i = 0; i < n; i++) {
    v[i] = m[s[i]];
  }
  auto f = [&](int a, int b) {
    if (a == 0) {
      if (b == 1)
        return b;
      else
        return a;
    } else if (a == 1) {
      if (b == 0)
        return a;
      else
        return b;
    } else {
      if (b == 1)
        return a;
      else
        return b;
    }
  };
  for (int i = 0; i < n; i++) {
    pf[i] = v[i];
    if (i)
      pf[i] = f(pf[i], pf[i - 1]);
  }
  for (int i = n - 1; i >= 0; i--) {
    sf[i] = v[i];
    if (i != n - 1)
      sf[i] = f(sf[i], sf[i + 1]);
  }
  //   for (int i = 0; i < n; i++) {
  //     cerr << pf[i] << " ";
  //   }
  //   cerr << endl;
  //   for (int i = 0; i < n; i++) {
  //     cerr << sf[i] << " ";
  //   }
  //   cerr << endl;
  int R = 0, P = 0, S = 0;
  for (int i = 0; i + 1 < n; i++) {
    int x = f(pf[i], sf[i + 1]);
    if (x == 0)
      R++;
    else if (x == 1)
      P++;
    else
      S++;
  }
  if (c == 'R')
    cout << R << endl;
  else if (c == 'P')
    cout << P << endl;
  else
    cout << S << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}