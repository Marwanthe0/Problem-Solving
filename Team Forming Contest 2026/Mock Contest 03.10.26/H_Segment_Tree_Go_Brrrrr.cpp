#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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

// for each prime pi and its power ai, (pi^(ai + 1) - 1)/(pi - 1);
vector<int> isprime(N + 5, 0), primes, spf(N + 5, 0);
int mod(int x, int m = M) { return x % m; }
void sieve() {
  for (int i = 2; i <= N; i++) {
    if (isprime[i] == 0) {
      spf[i] = i;
      primes.push_back(i);
      for (int j = i * i; j <= N; j += i) {
        isprime[j] = 1, spf[j] = i;
      }
    }
  }
}
int binexp(int a, int b) {
  int ans = 1ll;
  while (b) {
    if (b & 1)
      ans = mod(ans * 1ll * a);
    a = mod(a * 1ll * a);
    b >>= 1ll;
  }
  return mod(ans);
}
int invMod(int x) { return binexp(x, M - 2); }
int divans(int pi, int ai) {
  int up = mod(binexp(pi, ai + 1) - 1 + M);
  int low = pi - 1;
  return mod(up * 1ll * invMod(low));
}
void marwan(int cs) {
  cout << "Case " << cs << ": ";
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (auto p : primes) {
    if (p * p > n)
      break;
    while (n % p == 0) {
      n /= p;
      mp[p]++;
    }
  }
  if (n > 1)
    mp[n]++;
  int ans = 1ll;
  for (auto [x, y] : mp) {
    ans = mod(ans * 1ll * divans(x, y * m));
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    marwan(i);
  }
  return 0;
}