#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 300005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
vector<int> dvs[N + 1], freq(N + 1, 0), mls(N + 1, 0);
void pre() {
  for (int i = 2; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      dvs[j].push_back(i);
    }
  }
}
void marwan() {
  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    int g = __gcd(x, v[i]);
    for (int d : dvs[g])
      mls[d] += v[i];
    freq[v[i]]++;
  }
  vector<int> divs = dvs[x];
  make_unique(divs);
  //   for (int i = 0; i < divs.size(); i++) {
  //     int vl = divs[i];
  //     for (int j = vl; j <= N; j += vl) {
  //       if (freq[j])
  //         mls[vl] += freq[j] * j;
  //     }
  //   }
  int ans = 0;
  for (auto vl : divs)
    ans = max(ans, mls[vl]);
  //   cerr << endl;
  cout << ans << endl;
  for (auto vl : divs)
    mls[vl] = 0;
  for (auto vl : v)
    freq[vl] = 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}