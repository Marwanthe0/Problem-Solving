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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    unordered_map<int, pair<int, int>> m;
    int lim = min(n, 3000ll);
    for (int i = 0; i < lim; i++) {
        for (int j = i + 1; j < lim; j++) {
            // cerr << v[i] << " " << v[j] << endl;
            if (m.count(v[i] + v[j])) {
                auto [x, y] = m[v[i] + v[j]];
                // cerr << i << " " << j << " " << x << " " << y << endl;
                if (x != i && x != j && y != i && y != j) {
                    yes;
                    cout << i + 1 << " " << j + 1 << " " << x + 1 << " " << y + 1 << endl;
                    return;
                }
            }
            m[v[i] + v[j]] = {i, j};
        }
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}