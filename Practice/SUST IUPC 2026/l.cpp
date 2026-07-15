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
    int n, k;
    cin >> n >> k;
    vector<int> v(n), lis(n, 1);
    vector<int> t;
    int sum = 0ll;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        sum += v[i];
        auto it = lower_bound(all(t), v[i]);
        if (it == t.end()) {
            t.push_back(v[i]);
        } else
            *it = v[i];
        lis[i] = t.size();
        cerr << lis[i] << " ";
        if (i)
            lis[i] = max(lis[i], lis[i - 1]);
        auto tt = lower_bound(all(t), (int)t.size());
        if (tt == t.end()) {
            int x = lis[i];
            int lx = lis[i] + k - 1;
            int sss = (lx * 1l * (lx + 1)) / 2ll;
            sss -= (x * 1ll * (x - 1)) / 2ll;
            int tsum = sum + sss;
            cout << tsum;
        } else {
            int tsum = sum + k * 1ll * lis[i];
            cout << tsum;
        }
        // if (i)
        //     lis[i] = max(lis[i], lis[i - 1]);
        // cerr << lis[i] << " ";
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
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