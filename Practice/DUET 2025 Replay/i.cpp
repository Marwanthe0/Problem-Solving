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
    int mx = 0;
    for (auto &vl : v) {
        cin >> vl;
        mx = max(mx, __lg(vl));
    }
    for (auto vl : v) {
        for (int i = mx; i >= 0; i--) {
            cout << (1 & (vl >> i));
        }
        cout << endl;
    }
    for (int i = mx; i >= 0; i--) {
        vector<int> t(n, 0), ones;
        int count = 0;
        for (int j = 0; j < n; j++) {
            t[j] = (1 & (v[j] >> i));
            count += t[j];
            if (t[j])
                ones.push_back(j);
        }
        if (count > 1 && count < n) {
            
        }
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