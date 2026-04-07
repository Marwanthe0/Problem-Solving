#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 100000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<vector<int>> dv(N + 1);
void sieve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i)
            dv[j].push_back(i);
    }
}
int lcm(int a, int b) {
    return (a / __gcd(a, b)) * 1ll * b;
}
void marwan() {
    int n;
    cin >> n;
    int sum = 0ll;
    for (int k = 2; k <= n - 1; k++) {
        int c = n - k;
        for (auto vl : dv[k]) {
            int g = vl;
            sum += lcm(c, g);
        }
    }
    cout << sum << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    marwan();
    return 0;
}