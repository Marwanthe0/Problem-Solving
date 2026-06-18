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
    vector<int> a(n), b(n), t;
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    t = a;
    sort(all(t));
    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        if (t[i] > b[i]) {
            minus;
            return;
        }
        pos[t[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && a[j] > b[i]) {
            j++;
        }
        // cerr << i << " " << j << endl;
        ans += j - i;
        int x = a[j];
        while (j > i) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = x;
    }
    cout << ans << endl;
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