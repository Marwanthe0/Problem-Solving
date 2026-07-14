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
    for (auto &vl : v)
        cin >> vl;
    int rem = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i - 1] >= i) {
            rem += v[i - 1] - i;
            v[i - 1] = i;
        } else if (v[i - 1] + rem < i) {
            no;
            return;
        } else {
            rem -= i - v[i - 1];
            v[i - 1] = i;
        }
    }
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
            no;
            return;
        }
    }
    yes;
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