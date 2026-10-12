#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
int n;
vector<int> v, divs[N + 1];
void pre() {
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i)
      divs[j].push_back(i);
  }
}
void marwan() {
  cin >> n;
  v.assign(n, 0);
  vector<int> cur(n + 2, 0);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int idx = 0; idx <= n + 1; idx++)
    cur[idx] = idx != 1;

  for (int i = n - 1; i >= 0; i--) {
    for (auto d : divs[v[i]]) {
      if (d > i + 1)
        break;
      cur[d] = (cur[d] + cur[d + 1]) % M;
    }
  }
  cout << cur[1] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  marwan();
  return 0;
}