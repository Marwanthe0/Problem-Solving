#include <bits/stdc++.h>

using namespace std;

using ll = int64_t;

void marwan () {
  ll n, b, c;
  cin >> n >> b >> c;
  if (b == 0 && c == 0) {
    cout << -1 << "\n";
    return;
  }
  
  auto check = [&](ll mid) -> bool {
    if (mid < c) return false;
    mid -= c;
    ll cnt = mid / b + 1;
    ll rem = n - cnt;
    ll need = c + (mid / b * b);
    if (need <= rem) return true;
    return false;
  };
  ll hi = n, lo = 0, ret = hi;
  while (hi >= lo) {
    ll mid = (hi + lo) / 2;
    if (check(mid)) ret = mid, hi = mid - 1;
    else lo = mid + 1;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) marwan();
}
