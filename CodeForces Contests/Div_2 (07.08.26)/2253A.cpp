#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
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
vector<int> prime;
void sieve() {
    prime.assign(N + 1, 0);
    for (int i = 2; i * i <= N; i++) {
        if (prime[i] == 0) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = 1;
            }
        }
    }
}
void marwan() {
    int n;
    cin >> n;
    if (prime[n + 1] == 0) {
        yes;
    } else
        no;
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