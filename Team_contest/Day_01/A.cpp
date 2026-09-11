#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve_case() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int left = a[0] * i;
    int right = (n - i) * a[i];
    ans = max(ans, left + right);
  }
  cout << ans << "\n";
}

int32_t main() {
  int t;
  cin >> t;
  while (t--) {
    solve_case();
  }
}