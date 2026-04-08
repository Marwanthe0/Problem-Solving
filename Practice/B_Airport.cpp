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
    int n, m;
    cin >> n >> m;
    multiset<int> ms, ts;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        ms.insert(x);
        ts.insert(x);
    }
    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        if (ms.empty())
            break;
        auto it = (--ms.end());
        int top = *it;
        ms.erase(it);
        mx += top;
        if (top - 1)
            ms.insert(top - 1);
    }
    for (int i = 0; i < n; i++) {
        if (ts.empty())
            break;
        auto it = (ts.begin());
        int top = *it;
        ts.erase(it);
        mn += top;
        if (top - 1)
            ts.insert(top - 1);
    }
    cout << mx << " " << mn << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}