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
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  sort(all(v));
  //   for (auto vl : v)
  //     cout << vl << " ";
  //   cout << endl;
  reverse(all(v));
  int sum = 0;
  for (int i = n, j = 0; i >= 1; i--) {
    int val = (i) / k + ((i) % k != 0);
    sum += val * v[i - 1];
    // cout << val << " ";
  }
  //   cout << endl;
  vector<int> bad, prev;
  for (int i = 0; i < k; i++) {
    int tsum = 0;
    for (int j = i; j < n; j += k) {
      tsum += v[j];
    }
    bad.push_back(tsum);
  }
  prev = bad;
  vector<int> nw;
  for (int i = 0; i < n; i++) {
    int j = (i % k);
    // cerr << j << " " << prev[j] << " " << v[i] << endl;
    bad.push_back(prev[j] - v[i]);
    nw.push_back(prev[j] - v[i]);
    if (j == k - 1) {
      prev.clear();
      for (auto vl : nw)
        prev.push_back(vl);
      nw.clear();
    }
  }
  vector<int> ans = {sum};
  for (int i = 0; i + 1 < n; i++) {
    sum -= bad[i];
    // cout << sum << " ";
    ans.push_back(sum);
  }
  reverse(all(ans));
  for (auto vl : ans)
    cout << vl << " ";
  cout << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}