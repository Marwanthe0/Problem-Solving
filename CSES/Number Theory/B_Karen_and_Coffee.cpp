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
void marwan() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<pair<int, int>> v(n);
    vector<int> dif(N, 0);
    for (auto &[x, y] : v) {
        cin >> x >> y;
        dif[x]++, dif[y + 1]--;
    }
    for (int i = 1; i < N; i++) {
        dif[i] += dif[i - 1];
    }
    for (int i = 1; i < N; i++) {
        if (dif[i] < k)
            dif[i] = 0;
        else
            dif[i] = 1;
    }
    for (int i = 1; i < N; i++) {
        dif[i] += dif[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << dif[r] - dif[l - 1] << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}