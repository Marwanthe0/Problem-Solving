#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e7
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x)                                                         \
  sort(all((x)));                                                              \
  (x).erase(unique(all((x))), (x).end())
vector<int> primes(N, 0), p;
void pre() {
  for (int i = 2; i * i <= N; i++) {
    if (!primes[i]) {
      for (int j = i * i; j <= N; j += i)
        primes[j] = 1;
    }
  }
  for (int i = 2; i <= N; i++)
    if (!primes[i])
      p.push_back(i);
}
void marwan() {
  int n;
  cin >> n;
  cout << p[n - 1] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  pre();
  //   cout << p.size() << endl;
  //   return 0;
  //   for (int i = 0; i < 100; i++)
  //     cout << p[i] << " ";
  //   return 0;
  //   int t;
  //   cin >> t;
  //   while (t--) {
  marwan();
  //   }
  return 0;
}