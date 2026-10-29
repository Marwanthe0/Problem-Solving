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
  string s;
  cin >> s;
  int x;
  cin >> x;
  int n = s.size();
  vector<int> v(n, -1);
  for (int i = 0; i < n; i++) {
    if (i - x < 0 && i + x < n) {
      if (v[i + x] == -1)
        v[i + x] = s[i] - '0';
      else if (v[i + x] != s[i] - '0') {
        minus;
        return;
      }
    }
    if (i + x >= n && i - x >= 0) {
      if (v[i - x] == -1)
        v[i - x] = s[i] - '0';
      else if (v[i - x] != s[i] - '0') {
        minus;
        return;
      }
    }
    if (s[i] == '0') {
      if (i - x >= 0) {
        if (v[i - x] == -1)
          v[i - x] = 0;
        else if (v[i - x] != 0) {
          minus;
          return;
        }
      }
      if (i + x < n) {
        if (v[i + x] == -1)
          v[i + x] = 0;
        else if (v[i + x] != 0) {
          minus;
          return;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i - x >= 0 && i + x < n) {
      if (s[i] == '0') {
        if (v[i - x] == 1 || v[i + x] == 1) {
          minus;
          return;
        } else
          v[i - x] = v[i + x] = 0;
      } else {
        if (v[i - x] == 0 && v[i + x] == 0) {
          minus;
          return;
        } else if (v[i - x] == 1 || v[i + x] == 1) {
          continue;
        } else if (v[i - x] == 0)
          v[i + x] = 1;
        else if (v[i + x] == 0)
          v[i - x] = 1;
        else
          v[i - x] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i] != -1)
      cout << v[i];
    else {
      if (i - x >= 0)
        cout << s[i - x];
      else if (i + x < n)
        cout << s[i + x];
    }
  }
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