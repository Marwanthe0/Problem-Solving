#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
void marwan() {
  int n, q;
  cin >> n >> q;
  pbds<int> pb;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pb.insert(x);
  }
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int vl;
      cin >> vl;
      pb.insert(vl);
    } else if (op == 2) {
      if (pb.size() < 2) {
        cout << -1 << endl;
        continue;
      }
      int x = *(--pb.end());
      pb.erase(--pb.end());
      int y = *(--pb.end());
      pb.erase(--pb.end());
      pb.insert(__gcd(x, y));
      cout << __gcd(x, y) << endl;
    } else if (op == 3) {
      int l, r;
      cin >> l >> r;
      int low = pb.order_of_key(l), high = pb.order_of_key(r + 1);
      cout << high - low << endl;
    } else {
      int pos;
      cin >> pos;
      if (pos > pb.size())
        cout << -1 << endl;
      else {
        cout << *pb.find_by_order(pos - 1) << endl;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}