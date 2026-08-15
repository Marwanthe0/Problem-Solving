#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int q, v;
    cin >> q >> v;
    multiset<int> ms;
    int time = 0;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            ms.insert(b - a);
        } else {
            int t;
            cin >> t;
            if (ms.empty()) {
                cout << -1 << endl;
            } else {
                cout << min(v, *(--ms.end()) + t) << endl;
                ms.erase(--ms.end());
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}