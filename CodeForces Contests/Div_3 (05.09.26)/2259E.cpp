#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> diff(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (v[i] >= 0) {
      int l = max(0ll, (i - v[i]) + 1), r = min(n - 1, (i + v[i]) - 1);
      if (l <= r)
        diff[l]++, diff[r + 1]--;
    }
  }
  for (int i = 1; i < n; i++)
    diff[i] += diff[i - 1];
  string ans;
  for (int i = 0; i < n; i++) {
    // cerr << diff[i] << " ";
    if (diff[i] == 0) {
      ans.push_back('1');
    } else
      ans.push_back('0');
  }
  //   cerr << endl;
  //   cerr << ans << endl;
  for (int i = 0; i < n; i++) {
    if (v[i] == -1)
      continue;
    bool flag = false;
    if (i - v[i] >= 0 && ans[i - v[i]] == '1') {
      //   cerr << i << " " << v[i] << endl;
      flag = true;
    }
    if (i + v[i] < n && ans[i + v[i]] == '1') {
      //   cerr << i << " " << v[i] << endl;
      //   minus;
      //   return;
      flag = true;
    }
    if (!flag) {
      minus;
      return;
    }
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    marwan();
  }
  return 0;
}