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
void print(set<int> &s) {
    for (auto vl : s)
        cerr << vl << " ";
    cerr << endl;
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, set<int>> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]].insert(i);
    }
    set<int> s;
    int count = 0;
    for (auto it = m.rbegin(); it != m.rend(); it++) {
        int cnt = 0;
        cerr << it->first << ":::" << endl;
        print(it->second);
        while (cnt < it->second.size()) {
            int x = -1;
            for (auto &vl : it->second) {
                if (s.count(vl + 1) || s.count(vl - 1)) {
                    s.insert(vl);
                    x = vl;
                    continue;
                }
            }
            if (x == -1) {
                count++;
            } else
                it->second.erase(x);
            cnt++;
        }
    }
    cout << count << endl;
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