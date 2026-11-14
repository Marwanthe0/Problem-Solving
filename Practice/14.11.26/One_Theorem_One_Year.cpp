#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
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
vector<int> v;
int n, k;
int f(int i) {
    if (i == n)
        return 1;
    int ans = 0;
    for (auto vl : v) {
        ans += (vl * 1ll * f(i + 1)) % M;
        ans %= M;
    }
    return ans;
}
void marwan(int cs) {
    cin >> n >> k;
    v.clear();
    for (int i = 0; i < k; i++) {
        v.push_back(primes[i]);
        cerr << v[i] << " ";
    }
    cerr << endl;
    int ans = f(0);
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}