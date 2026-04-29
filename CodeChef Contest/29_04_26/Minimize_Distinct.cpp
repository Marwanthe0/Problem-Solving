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
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_set<int> s;
    for (auto &vl : v) {
        cin >> vl;
        s.insert(vl);
    }
    set<int> a, cnt;
    int tn = s.size();
    for (auto vl : v) {
        if (s.count(vl + 2))
            a.insert(vl);
    }
    for (auto vl : a) {
        if (a.count(vl + 1))
            cnt.insert(vl);
    }
    for (int i = 1; i <= n; i++) {
        if (cnt.size()) {
            cout << tn - 2 << " ";
        } else if (a.size()) {
            cout << tn - 1 << " ";
        } else
            cout << tn << " ";
        if (cnt.count(i))
            cnt.erase(i);
        if (a.count(i))
            a.erase(i);
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