#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> primes;
vector<bool> isprime(N + 1, 0);
void sieve() {
    for (int i = 2; i * i <= N; i++) {
        if (!isprime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isprime[j] = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++)
        if (!isprime[i])
            primes.push_back(i);
    for (int i = 1; i <= N; i++)
        primes.push_back(i);
}
int lcm(int a, int b) { return ((a / __gcd(a, b)) * 1ll * b); }
void marwan() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << primes[i] * primes[i + 1] << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}