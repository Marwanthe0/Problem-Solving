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
  string s;
  cin >> s;
  if (s[0] == '0') {
    minus;
    return;
  }
  for (int i = 1; i < n; i++)
    if (s[i] == s[i - 1] && s[i] == '0') {
      minus;
      return;
    }
  int rem = 0;
  vector<int> ans;
  if (s[0] == '+')
    ans.push_back(1);
  else
    ans.push_back(-1);
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      if (s[i - 1] == '+') {
        if (ans.back() == 1)
          ans.push_back(2);
        else
          ans.push_back(1);
      } else {
        if (ans.back() == -1)
          ans.push_back(-2);
        else
          ans.push_back(-1);
      }
    } else {
      if (s[i] == '+') {
        if (i + 1 < n && s[i + 1] == '+')
          ans.push_back(2);
        else
          ans.push_back(1);
      } else if (s[i] == '0')
        ans.push_back(0);
      else {
        if (i + 1 < n && s[i + 1] == '-')
          ans.push_back(-2);
        else
          ans.push_back(-1);
      }
    }
  }
  vector<int> tans(n, 0);
  for (int i = n - 1; i > 0; i--) {
    tans[i] = ans[i] - ans[i - 1];
  }
  tans[0] = ans[0];
  for (auto vl : tans)
    cout << vl << " ";
  cout << endl;
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

// ID:1788882383311