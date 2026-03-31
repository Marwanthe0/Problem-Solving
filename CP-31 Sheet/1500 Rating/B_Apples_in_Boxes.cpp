#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Tom" << endl
#define no cout << "Jerry" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, k;
    cin >> n >> k;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    for (auto vl : ms)
        cout << vl << " ";
    cout << endl;
    int count = 0;
    while (!ms.empty()) {
        auto it = (--ms.end());
        int x = *it;
        cout << x << " ";
        ms.erase(it);
        if (x != 1)
            ms.insert(x - 1);
        // int mn = *ms.begin(), mx = *(--ms.end());
        // if (mx - mn > k) {
        //     if (count & 1) {
        //         yes;
        //         return;
        //     } else {
        //         no;
        //         return;
        //     }
        // }
        // count++;
    }
    if (count & 1) {
        yes;
    } else
        no;
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