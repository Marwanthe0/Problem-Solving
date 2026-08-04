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
    int start = INT_MAX;
    multiset<int> ms;
    for (auto &vl : v) {
        cin >> vl;
        ms.insert(vl);
        if (vl > 0)
            start = min(vl, start);
    }
    int sum = accumulate(all(v), 0ll);
    if (sum <= 0) {
        minus;
        return;
    }
    if (ms.find(start) != ms.end()) {
        ms.erase(ms.find(start));
    }
    vector<int> ans = {start};
    int tsum = start;
    for (int i = 1; i < n; i++) {
        auto x = ms.lower_bound((-tsum) + 1);
        if (x == ms.end()) {
            minus;
            return;
        }
        tsum += *x;
        ans.push_back(*x);
        ms.erase(x);
    }
    tsum = 0ll;
    for (auto vl : ans) {
        tsum += vl;
        cout << tsum << " ";
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