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
int n, m;
vector<vector<pair<int, long double>>> v;
vector<vector<long double>> perc;
vector<int> vis;
class dot {
public:
  long double cost;
  int node, used;
  dot(long double cost, int node, int used) {
    this->cost = cost;
    this->node = node;
    this->used = used;
  }
  bool operator<(const dot &other) const { return this->cost < other.cost; }
};

void marwan() {
  cin >> n >> m;
  v.assign(n + 1, vector<pair<int, long double>>());
  perc.assign(n + 1, vector<long double>(2, 0));
  vis.assign(n + 1, 0);
  perc[1][0] = perc[1][1] = 1;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, (long double)(c) / 100});
    v[b].push_back({a, (long double)(c) / 100});
  }
  priority_queue<dot> ms;
  dot fst = dot(1, 1, 0);
  ms.push(fst);
  while (!ms.empty()) {
    dot nd = ms.top();
    ms.pop();
    if (nd.cost < perc[nd.node][nd.used])
      continue;
    for (auto vl : v[nd.node]) {
      int child = vl.first;
      long double childcost = vl.second;
      if (!nd.used) {
        // 100% nibo
        if (nd.cost > perc[child][1]) {
          ms.push({nd.cost, child, 1});
          perc[child][1] = nd.cost;
        }
        // nibona
        if (nd.cost * childcost > perc[child][0]) {
          ms.push({nd.cost * childcost, child, 0});
          perc[child][0] = nd.cost * childcost;
        }
      } else {
        if (nd.cost * childcost > perc[child][1]) {
          ms.push({nd.cost * childcost, child, 1});
          perc[child][1] = nd.cost * childcost;
        }
      }
    }
  }
  //   for (int i = 1; i <= n; i++) {
  //     cerr << perc[i][0] << " " << perc[i][1] << endl;
  //   }
  cout << fixed << setprecision(6) << perc[n][1] * 100 << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}