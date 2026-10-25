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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
struct Node {
  int len, cnt;
};

Node combine(Node a, Node b) {
  if (a.len > b.len)
    return a;

  if (b.len > a.len)
    return b;

  return {a.len, (a.cnt + b.cnt) % M};
}

struct Fenwick {
  int n;
  vector<Node> bit;

  Fenwick(int n) {
    this->n = n;
    bit.assign(n + 1, {0, 0});
  }

  void update(int idx, Node val) {
    while (idx <= n) {
      bit[idx] = combine(bit[idx], val);
      idx += idx & -idx;
    }
  }

  Node query(int idx) {
    Node ans = {0, 0};

    while (idx > 0) {
      ans = combine(ans, bit[idx]);
      idx -= idx & -idx;
    }

    return ans;
  }
};

void marwan() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &vl : v)
    cin >> vl;
  vector<int> t = v;
  make_unique(t);
  Fenwick sg1(t.size() + 2);
  for (auto vl : v) {
    int pos = lower_bound(all(t), vl) - t.begin() + 1;
    auto tmp = sg1.query(pos - 1);
    int ways = tmp.len == 0 ? 1 : tmp.cnt;
    sg1.update(pos, {tmp.len + 1, ways});
  }
  cout << sg1.query(t.size() + 2).len << " " << sg1.query(t.size() + 2).cnt
       << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}