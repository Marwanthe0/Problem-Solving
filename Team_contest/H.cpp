#include <bits/stdc++.h>

using namespace std;

#define int long long

int LCM(int a, int b) {
  return a / __gcd(a, b) * b;
}

void solve_case() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "1\n1\n";
    return;
  }

  auto backup = n;

  vector<int> f;

  for (int i = 2; i * i <= n; i++) {
    if (n % i) continue;
    int p = 1;
    while (n % i == 0) {
      n /= i;
      p *= i;
    }
    f.push_back(p);
  }
  if (n > 1) {
    f.push_back(n);
  }

  vector<int> ans;
  for (int i = 0; i < (int)f.size(); i++) {
    ans.push_back(backup / f[i]);
  }
  ans.push_back(backup);
  cout << ans.size() << "\n";
  sort(ans.begin(), ans.end());
  for (auto &it : ans) cout << it << " ";
  cout << "\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    solve_case();
  }
}