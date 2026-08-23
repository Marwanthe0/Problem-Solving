
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fact[1000000];

int pwr(int x, int p, int mod) {

  ll a = x;

  while (p) {
    a = ((a % mod) * 1ll * (a % mod)) % mod;
    p = p >> 1;
  }
  return a;
}

ll abc(int n, int r, int MOD) {

  ll tem = (fact[r] * 1ll * fact[n - r]) % MOD;

  tem = pwr(tem, MOD - 1, MOD);

  return ((tem % MOD) * 1ll * (fact[n] % MOD)) % MOD;
}

ll xyz(ll n, ll m, int p) {

  if (n == 0)
    return 1;

  if (m == 0)
    return 1;

  int ni = n % p;
  int mi = m % p;

  return (xyz(n / p, m / p, p) % p) * 1ll * (abc(ni, mi, p) % p) % p;
}

ll C(ll n, ll r, int MOD) {

  fact[0] = 1;
  for (int i = 1; i < MOD; i++)
    fact[i] = (i * 1ll * (fact[i - 1] % MOD)) % MOD;

  return xyz(n, r, MOD);
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    int p;
    cin >> n >> k >> p;
    cout << C(n, k, p) << endl;
  }
}