#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define M 1000000007
#define N 5000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> phi(N + 1, 0ll);
void pre() {
    for (int i = 1; i <= N; i++)
        phi[i] = i;
    for (int i = 2; i <= N; i++) {
        if (phi[i] == i) {
            phi[i] = i - 1;
            for (int j = 2 * i; j <= N; j += i) {
                phi[j] = ((phi[j] * 1ll * (i - 1)) / i);
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        phi[i] = (phi[i] * 1ll * phi[i]);
        phi[i] += phi[i - 1];
    }
}
void marwan(int cs) {
    int l, r;
    cin >> l >> r;
    cout << "Case " << cs << ": ";
    cout << phi[r] - phi[l - 1] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    // for (int i = 1; i <= N; i++) {
    //     cerr << i << " " << phi[i] << endl;
    // }
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}