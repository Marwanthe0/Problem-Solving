#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    int pos = 0, ans = 0ll;
    while (!ms.empty()) {
        auto it = ms.lower_bound(pos);
        if (it == ms.begin()) {
            ans += abs(pos - *it);
            pos = *it;
            ms.erase(it);
        } else if (it == ms.end()) {
            it--;
            ans += abs(pos - *it);
            pos = *it;
            ms.erase(it);
        } else {
            auto tt = --ms.lower_bound(pos);
            if (abs(pos - *it) < abs(pos - *tt)) {
                ans += abs(pos - *it);
                pos = *it;
                ms.erase(it);
            } else {
                ans += abs(pos - *tt);
                pos = *tt;
                ms.erase(tt);
            }
        }
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}