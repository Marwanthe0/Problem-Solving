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
  string s;
  cin >> s;
  vector<int> dif(n + 1, 0), dif2(n + 1, 0);
  map<char, vector<int>> m;
  for (int i = 0; i < n; i++)
    m[s[i]].push_back(i);
  //   for (auto c : "2056") {
  //     cerr << c << endl;
  //     for (auto pos : m[c])
  //       cerr << pos << " ";
  //     cerr << endl;
  //   }
  //   cerr << endl;
  for (int i = 0; i < n; i++) {
    int p2, p0, p22, p5, p6;
    auto f2 = lower_bound(all(m['2']), i);
    if (f2 == m['2'].end()) {
      if (i - 1)
        dif[i - 1]++;
      continue;
    } else {
      p2 = *f2;
    }
    auto f0 = upper_bound(all(m['0']), p2);
    if (f0 == m['0'].end()) {
      if (i - 1)
        dif[i - 1]++;
      continue;
    } else
      p0 = *f0;
    auto f22 = upper_bound(all(m['2']), p0);
    if (f22 == m['2'].end()) {
      if (i - 1)
        dif[i - 1]++;
      continue;
    } else
      p22 = *f22;
    auto f6 = upper_bound(all(m['6']), p22), f5 = upper_bound(all(m['5']), p22);
    if (f5 == m['5'].end()) {
      //   dif[i] += n - i;
      if (i - 1)
        dif[i - 1]++;
      continue;
    } else
      p5 = *f5;
    if (f6 == m['6'].end()) {
      // restr = p5...n
      dif[p6]++;
      dif2[p5 - 1]--;
      continue;
    } else
      p6 = *f6;
    if (p6 < p5) {
      //   dif[i] += n - i;
      continue;
    } else {
      int cnt = p5 - i + (n - p6);
      // restr = p5...(p6 - 1)
      dif[p6 - 1]++;
      dif2[p5 - 1]++;
    }
  }
  for (int i = n - 1, j = 1; i >= 0; i--) {
    if (i != n - 1)
      dif[i] = dif[i + 1];
  }
  vector<int> ans(n + 1, 0);
  for (int i = n - 1, j = 1; i >= 0; i--, j++) {
    ans[i] = n * j - dif[i] * j;
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;
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