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
vector<int> isprime(N + 5, 0), primes, spf(N + 5, 0);
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
      ans = (ans * 1ll * a) % M;
    a = (a * 1ll * a) % M;
    b >>= 1ll;
  }
  return ans;
}
void marwan(int cs) {
  cout << "Case " << cs << ": ";
  int c, b, n;
  // b = p+q, c = pq,a = 1;
  // ax^2 - bx + c
  // p,q = (b+-sqrt(b^2 - 4ac))/2a;
  // p = (b + sqrt(b^2 - 4c))/2
  // q = (b - sqrt(b^2 - 4c))/2
  cin >> b >> c >> n;
  long double val = sqrt((long double)(binexp(b, 2) - 4 * c));
  int p = (b + val) / 2, q = (b - val) / 2;
  cout << (binexp(p, n) + binexp(q, n)) % M << endl;
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