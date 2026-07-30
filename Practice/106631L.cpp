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
    for (auto &vl : v) {
        cin >> vl;
        vl %= 2;
    }
    if (count(all(v), 0) == 0 || count(all(v), 1) == 0) {
        cout << 1 << endl;
    } else {
        int cnt = 0, idx = n - 1;
        while (idx >= 0 && v[idx] == v.back())
            cnt++, idx--;
        cout << count(all(v), v.back()) - (cnt - 1) << endl;
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