
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fact[1000000];

int pwr(int x, int p, int mod) {

  ll t = 1, a = x;

  while (p) {
    a = (a * a) % mod;
    p = p >> 1;
  }
  return t;
}

ll abc(int n, int r, int MOD) {

  ll tem = (fact[r] * fact[n - r]) % MOD;

  tem = pwr(tem, MOD - 1, MOD);

  return (tem * fact[n]) % MOD;
}

ll xyz(ll n, ll m, int p) {

  if (n == 0)
    return 1;

  if (m == 0)
    return 1;

  int ni = n % p;
  int mi = m % p;

  return xyz(n / p, m / p, p) * abc(ni, mi, p) % p;
}

ll C(ll n, ll r, int MOD) {

  fact[0] = 1;
  for (int i = 1; i != MOD; i++)
    fact[i] = (i * fact[i - 1]) % MOD;

  return xyz(n, r, MOD);
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    int p;

    cin >> n >> k >> p;

    printf("%lld", C(n, k, p));
  }
}