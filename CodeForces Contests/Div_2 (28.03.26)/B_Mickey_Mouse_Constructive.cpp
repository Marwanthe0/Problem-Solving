#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 676767677
#define N 2000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> dv(N + 2, 0);
void sieve() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            dv[j] = (dv[j] + 1) % M;
        }
    }
}
void marwan() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 1 << endl;

    } else {
        cout << dv[abs(a - b)] << endl;
    }
    for (int i = 0; i < a; i++)
        cout << 1 << " ";
    for (int i = 0; i < b; i++)
        cout << -1 << " ";
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