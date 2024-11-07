#include <bits/stdc++.h>

using namespace std;

inline int in () {
  int x; scanf("%d", &x); return x;
}

void solve () {
  int n = in ();
  map<int, int> cnt;
  for (int i = 0; i < n; i++) cnt[in()] += 1;
  multiset<int> ms;
  for (auto &[_, x] : cnt) ms.insert(x);
  while (ms.size() > 1) {
    int r = *ms.rbegin(); ms.erase(--ms.end());
    int l = *ms.begin(); ms.erase(ms.begin());
    --l, --r;
    if (l) ms.insert(l);
    if (r) ms.insert(r);
    if (ms.empty()) ms.insert(0);
  }
  cout << *ms.begin() << endl;
}

/*
2 2 2 
1 1 2 
1 0 1 
0 0 0
*/

int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL);
  int t = 1;
  t = in();
  while (t--) solve ();
  return 0;
}