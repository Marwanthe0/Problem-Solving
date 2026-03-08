#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m, l;
    cin >> n >> m >> l;
    unordered_set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    multiset<int> ms;
    for (int i = 0; i < min(m, n + 1); i++)
        ms.insert(0);
    int rem = n;
    for (int i = 1; i <= l; i++) {
        auto it = ms.begin();
        ms.insert(*it + 1);
        ms.erase(it);
        if (s.count(i)) {
            auto it = --ms.end();
            ms.erase(it);
            if (ms.size() < rem)
                ms.insert(0);
            rem--;
        }
    }
    cout << *(--ms.end()) << endl;
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