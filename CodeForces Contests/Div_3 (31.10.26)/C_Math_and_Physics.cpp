#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    int one = 0;
    for (auto &vl : v) {
        cin >> vl;
        if (vl == 1)
            one++;
    }
    if (one == n) {
        minus;
        return;
    }

    bool flag = 0;
    for (int i = 1; i + 1 < n; i++) {
        if (v[i] != 1) {
            flag = true;
            break;
        }
    }
    
    if (flag) {
        cout << accumulate(all(v), 0ll) - 1 << endl;
    } else {
        cout << v[0] + v.back() - 1 << endl;
    }
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