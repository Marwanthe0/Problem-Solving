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
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int count1s = 0, count0s = 0, count1t = 0, count0t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] && a[i] != b[i])
            count1s++;
        else if (a[i] && a[i] == b[i])
            count1t++;
        else if (a[i] == 0 && a[i] == b[i])
            count0t++;
        else
            count0s++;
    }
    if (count0s + count1s == 0) {
        zero;
        return;
    } else if (count1s) {
        if (count1s & 1) {
            cout << 1 << endl;
        } else
            cout << 2 << endl;
        return;
    } else if (count0s) {
        if (count1t && count0t)
            cout << 2 << endl;
        else
            minus;
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