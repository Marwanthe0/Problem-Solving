#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 5000001
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
vector<int> isprime(N + 5, 0), primes, spf(N + 5, 0), pdvs(N + 5, 0);
void sieve() {
  for (int i = 1; i <= N; i++)
    spf[i] = i;
  for (int i = 2; i <= N; i++) {
    if (isprime[i] == 0) {
      primes.push_back(i);
      for (int j = i * i; j <= N; j += i) {
        isprime[j] = 1;
        if (spf[j] == j)
          spf[j] = i;
      }
    }
  }
}
void pre() {
  for (int x = 2; x <= N; x++) {
    pdvs[x] = pdvs[(x / spf[x])] + 1;
  }
  for (int i = 2; i <= N; i++)
    pdvs[i] += pdvs[i - 1];
}
void marwan() {
  int a, b;
  cin >> a >> b;
  cout << pdvs[a] - pdvs[b] << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  pre();
  int t;
  cin >> t;
  while (t--)
    marwan();
  return 0;
}