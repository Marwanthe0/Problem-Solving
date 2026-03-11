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
int sum(int a, int b, int c) {
    return (a ^ b) + (b ^ c) + (c ^ a);
}
void marwan() {
    int l, r;
    cin >> l >> r;
    int count = 0;
    vector<int> ans(3, 0);
    int idx = 0;
    for (int i = max(__lg(r), __lg(l)); i >= 0; i--) {
        if ((1 & (l >> i)) == 0 && (1 & (r >> i)) == 1) {
            count++;
            cerr << i << " ";
            ans[idx % 3] |= (1ll << i);
            idx++;
        }
    }
    cerr << endl;
    for (auto vl : ans)
        cout
            << vl
            << " ";
    cout << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    // int a, b, c;
    // cin >> a >> b >> c;
    // cout << sum(a, b, c) << endl;
    return 0;
}