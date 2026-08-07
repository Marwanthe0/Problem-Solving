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
    int ans = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i == 0 || v[i] != v[i - 1])
            ans++;
    }
    // cerr << ans << endl;
    if (n <= 2) {
        cout << ans << endl;
        return;
    }
    bool flag = false;
    for (int i = 2; i + 1 < n; i++) {
        if (v[i] != v[i - 1]) {
            if (v[i] == v[i + 1] && v[i - 1] == v[i - 2]) {
                cout << ans + 2 << endl;
                return;
            } else if (v[i] == v[i + 1]) {
                if (i - 2 >= 0 && v[i] == v[i - 2])
                    continue;
                flag = true;
            } else if (v[i - 1] == v[i - 2]) {
                if (i + 1 < n && v[i - 1] == v[i + 1])
                    continue;
                else
                    flag = true;
            }
        }
    }
    if (v[0] != v[1]) {
        if (v[1] == v[2])
            flag = true;
    }
    if (v.back() != v[n - 2]) {
        if (v[n - 2] == v[n - 3]) {
            flag = true;
        }
    }
    cout << ans + flag << endl;
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