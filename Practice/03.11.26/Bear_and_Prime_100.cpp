#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
// #define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
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
bool ask(int x) {
    cout << x << endl;
    fflush(stdout);
    string s;
    cin >> s;
    return s == "yes";
}
void marwan() {
    for (int i = 0; i < 20; i++) {
        if (ask(primes[i])) {
            if (primes[i] * primes[i] < 100 && ask(primes[i] * primes[i])) {
                cout << "composite" << endl;
                fflush(stdout);
                return;
            }
            for (int j = i + 1;; j++) {
                if (primes[j] * primes[i] > 100) {
                    break;
                }
                if (ask(primes[j])) {
                    cout << "composite" << endl;
                    fflush(stdout);
                    return;
                }
            }
            cout << "prime" << endl;
            fflush(stdout);
            return;
        }
        // cout << primes[i] << " ";
    }
    cout << "prime" << endl;
    fflush(stdout);
    return;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    marwan();
    return 0;
}