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
    int x = 0;
    for (auto &vl : v) {
        cin >> vl;
        x |= vl;
    }
    int y = 0;
    bool flag = true;
    int count = 0, ans = 0;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        y |= v[i];
        // cerr << y << endl;
        if (y == x) {
            count++, y = 0;
        }
    }
    cout << n - count << endl;
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