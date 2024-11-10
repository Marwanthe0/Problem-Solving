#include <bits/stdc++.h>

using namespace std;

void dbg(auto p) {
    for (auto &i : p) cerr << i << " "; cerr << endl;
}

void marwan () {
  int n, m, v;
  cin >> n >> m >> v;
  vector<int64_t> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int64_t sum = 0;
  vector<int> p(n, 0), s(n, 0);
  int got = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum >= v) {
      p[i] = ++got;
      sum = 0;
    }
  }
  sum = got = 0;
  for (int i = n - 1; ~i; --i) {
    sum += a[i];
    if (sum >= v) {
      s[i] = ++got;
      sum = 0;
    }
  }
  for (int i = 1; i < n; i++) a[i] += a[i - 1];
//   dbg(p); dbg(s);
  for (int i = 1; i < n; i++) p[i] = max(p[i], p[i - 1]);
  for (int i = n - 2; ~i; --i) s[i] = max(s[i], s[i + 1]);
  
  if (max(p.back(), s[0]) < m) {
    cout << -1 << "\n";
    return;
  }

  auto Getp = [&](int cnt) -> int {
    int hi = n - 1, lo = 0, ret = hi;
    while (hi >= lo) {
      int mid = (hi + lo) >> 1;
      if (p[mid] >= cnt) ret = mid, hi = mid - 1;
      else lo = mid + 1;
    }
    return ret + 1;
  };

  auto Gets = [&](int cnt) -> int {
    int hi = n - 1, lo = 0, ret = lo;
    while (hi >= lo) {
      int mid = (hi + lo) / 2;
      if (s[mid] >= cnt) ret = mid, lo = mid + 1;
      else hi = mid - 1;
    }
    return ret - 1;
  };
  int64_t ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] >= m) {
      ans = max(ans, a.back() - a[i]);
      break;
    }
  }
  for (int i = n - 1; i; --i) {
    if (s[i] >= m) {
      ans = max(ans, a[i - 1]);
      break;
    }
  }
  int i = 1, j = m - 1;
  while (i < m) {  
    int l = Getp(i);
    int r = Gets(j);
    // cerr << i << " " << j << " ";
    // cerr << l << " " << r << "\n";
    i += 1, j -= 1;
    if (l > r) continue;
    int64_t sum = a[r] - (l ? a[l - 1] : 0);
    ans = max(ans, sum);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) marwan();
}
