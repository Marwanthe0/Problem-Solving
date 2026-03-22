#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 10000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
void marwan() {
    vector<bool> is_prime(N + 1, true);
    vector<int> primes;
    is_prime[2] = true;
    primes.push_back(2);
    for (int i = 2; i <= N; i += 2)
        is_prime[i] = false;
    for (int i = 3; i * i <= N; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += 2 * i) {
                is_prime[j] = false;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 3; primes.size() < n; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
    cout << primes[n - 1] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}