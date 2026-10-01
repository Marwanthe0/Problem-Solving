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
void marwan() {
  int n;
  cin >> n;
  vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX)), t = dist;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> dist[i][j];
    }
  }
  //   t = dist;
  //   for (int k = 1; k <= n; k++) {
  //     for (int i = 1; i <= n; i++) {
  //       for (int j = 1; j <= n; j++) {
  //         if (dist[i][k] + dist[k][j] < dist[i][j]) {
  //           dist[i][j] = dist[i][k] + dist[k][j];
  //         }
  //       }
  //     }
  //   }
  //   int sum = 0;
  //   for (int i = 1; i <= n; i++) {
  //     for (int j = 1; j <= n; j++) {
  //       sum += dist[i][j];
  //     }
  //   }
  vector<int> dels(n), vis(n + 1, 0), ans;
  for (auto &vl : dels) {
    cin >> vl;
  }
  reverse(all(dels));
  vector<int> added;
  for (auto k : dels) {
    vis[k]++;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    int tsum = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (vis[i] && vis[j])
          tsum += dist[i][j];
      }
    }
    ans.push_back(tsum);
  }
  reverse(all(ans));
  for (auto vl : ans)
    cout << vl << " ";
  return;
  //   //
  //   for (auto vl : dels) {
  //     dist = t;
  //     for (int k = 1; k <= n; k++) {
  //       if (vis[k])
  //         continue;
  //       for (int i = 1; i <= n; i++) {
  //         for (int j = 1; j <= n; j++) {
  //           if (dist[i][k] + dist[k][j] < dist[i][j]) {
  //             dist[i][j] = dist[i][k] + dist[k][j];
  //           }
  //         }
  //       }
  //     }
  //     int sum = 0;
  //     for (int i = 1; i <= n; i++) {
  //       for (int j = 1; j <= n; j++) {
  //         if (vis[i] || vis[j])
  //           continue;
  //         sum += dist[i][j];
  //       }
  //     }
  //     vis[vl]++;
  //     cout << sum << " ";
  //   }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  marwan();
  return 0;
}