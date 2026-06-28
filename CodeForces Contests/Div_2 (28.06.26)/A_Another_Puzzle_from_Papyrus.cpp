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
    int n, c;
    cin >> n >> c;
    int ans = 0;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] >= b[i])
            ans += a[i] - b[i];
        else
            flag = false;
    }
    int ans2 = INT_MAX;
    sort(all(a));
    sort(all(b));
    ans2 = c;
    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            minus;
            return;
        }
        ans2 += a[i] - b[i];
    }
    if (flag == false)
        ans = INT_MAX;
    cout << min(ans, ans2) << endl;
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