#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 10000005
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
vector<int> primes;
vector<bool> isprime(N + 5, 0);
void sieve() {
    for (int i = 2; i <= N; i++) {
        if (isprime[i] == 0) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i) {
                isprime[j] = 1;
            }
        }
    }
}
void marwan(int cs) {
    int n;
    cin >> n;
    int count = 0;
    for (auto p : primes) {
        if (p + 1 >= n || p > n - p)
            break;
        if (!isprime[n - p]) {
            count++;
        }
    }
    cout << count << endl;
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