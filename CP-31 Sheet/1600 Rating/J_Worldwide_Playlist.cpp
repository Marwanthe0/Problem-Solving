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
void print(vector<int> &v) {
    for (int i = 1; i < v.size(); i++)
        cerr << v[i] << " ";
    cerr << endl;
}
void marwan() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), pos(n + 1, 0), pos2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos2[b[i]] = i;
    }
    int ans = pos[b.back()];
    for (int i = 2; i <= n; i++) {
        if (pos[b[i]] < pos[b[i - 1]]) {
            ans += n;
        }
    }
    ans -= n;
    cout << ans << endl;
    m--;

    auto contr = [&](int i) {
        int res = 0;
        if (i >= 2 && i <= n)
            res += (pos[b[i - 1]] < pos[b[i]] ? 0 : n);
        if (i == n)
            res += pos[b[i]];
        return res;
    };
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        int i, j;
        if (op == 1) {
            i = pos2[a[x]], j = pos2[a[y]];
        } else {
            i = x, j = y;
        }
        set<int> s;
        for (auto vl : {i, i + 1, j, j + 1}) {
            if (vl >= 2 && vl <= n)
                s.insert(vl);
        }
        for (auto vl : s) {
            ans -= contr(vl);
        }
        if (op == 1) {
            swap(pos[a[x]], pos[a[y]]);
            swap(a[x], a[y]);
        } else {
            swap(pos2[b[x]], pos2[b[y]]);
            swap(b[x], b[y]);
        }
        for (auto vl : s) {
            ans += contr(vl);
        }
        cout << ans << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}