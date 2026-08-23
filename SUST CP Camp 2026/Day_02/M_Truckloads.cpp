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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
int f(int l, int r, int k) {
  if (r - l + 1 <= k)
    return 1;
  int mid = (l + r) / 2;
  int left = f(l, mid, k);
  int right = f(mid + 1, r, k);
  return left + right;
}
bool marwan() {
  int n, k;
  if (!(cin >> n >> k))
    return false;

  cout << f(1, n, k) << endl;
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (marwan())
    ;

  return 0;
}
