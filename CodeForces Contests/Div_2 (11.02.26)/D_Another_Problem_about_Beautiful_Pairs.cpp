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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= min(n, v[i] * v[i]); j += v[i]) {
            int cka = i + j, ckb = i - j;
            if (cka >= 1 && cka <= n) {
                if (abs(i - cka) == v[i] * v[cka])
                    count++;
            }
            if (ckb >= 1 && ckb <= n) {
                if (abs(i - ckb) == v[i] * v[ckb] && v[i] != v[ckb])
                    count++;
            }
        }
    }
    cout << count << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}