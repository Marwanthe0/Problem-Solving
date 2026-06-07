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
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> row(n + 1, 0), col(n + 1, 0);
    while (q--) {
        int op, val;
        cin >> op >> val;
        if (op == 1) {
            int old = row[val];
            row[val] = n;
            ans += (n - old);
            cout << ans << endl;
        }
        else {
            
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}