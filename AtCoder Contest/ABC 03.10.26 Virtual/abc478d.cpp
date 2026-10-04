// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define M 1000000007
// #define N 1000005
// #define INF 1e17
// #define endl "\n"
// #define all(v) v.begin(), v.end()
// #define minus cout << "-1" << endl
// #define zero cout << "0" << endl
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define make_unique(x) \
//   sort(all((x))); \ (x).erase(unique(all((x))), (x).end())
// vector<pair<int, int>> f(vector<pair<int, int>> &t) {
//   sort(all(t));
//   vector<pair<int, int>> tt;
//   int last = 0, first = 0;
//   for (auto [x, y] : t) {
//     if (x > last) {
//       if (last)
//         tt.push_back({first, last});
//       first = x, last = y;
//     } else
//       last = max(last, y);
//   }
//   if (last)
//     tt.push_back({first, last});
//   return tt;
// }
// void marwan() {
//   int n, q;
//   cin >> n >> q;
//   vector<int> dif(n + 2, 0);
//   map<int, vector<pair<int, int>>> m;
//   while (q--) {
//     int a, b, c;
//     cin >> a >> b >> c;
//     m[c].push_back({a, b});
//   }
//   for (auto [x, y] : m) {
//     auto vt = f(y);
//     for (auto [i, j] : vt) {
//       //   cout << i << " " << j << endl;
//       //   dif[i]++, dif[j + 1]--;
//       dif[i]++, dif[j + 1]--;
//     }
//     // cout << endl;
//   }
//   for (int i = 1; i <= n; i++) {
//     dif[i] += dif[i - 1];
//     cout << dif[i] << " ";
//   }
//   cout << endl;
// }
// int32_t main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   marwan();
//   return 0;
// }

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
  int n, q;
  cin >> n >> q;
  vector<vector<int>> op(n + 1, vector<int>()), cl(n + 2, vector<int>());
  for (int i = 0; i < q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    op[a].push_back(c);
    cl[b + 1].push_back(c);
  }
  int dist = 0;
  map<int, int> m;
  for (int i = 1; i <= n; i++) {
    for (auto vl : op[i]) {
      m[vl]++;
      if (m[vl] == 1)
        dist++;
    }
    for (auto vl : cl[i]) {
      m[vl]--;
      if (m[vl] == 0)
        dist--;
    }
    cout << dist << " ";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}