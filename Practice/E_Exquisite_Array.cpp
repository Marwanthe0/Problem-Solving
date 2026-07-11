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
    vector<int> v(n), t;
    vector<vector<int>> m(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i)
            t.push_back(abs(v[i] - v[i - 1]));
    }
    for (auto vl : t)
        cerr << vl << " ";
    cerr << endl;
    n = t.size();
    for (int i = 0; i < n; i++)
        m[t[i]].push_back(i);
    vector<int> cur;
    for (auto vl : t)
        cout << vl << " ";
    cout << endl;
    cout << (n * (n + 1)) / 2 << " ";
    for (int x = 1; x < n; x++) {
        int count = 0;
        // cerr << x << endl;
        vector<int> next;
        int i = 0, j = 0;
        while (i < cur.size() && j < m[x].size()) {
            if (cur[i] < m[x][j])
                next.push_back(cur[i++]);
            else
                next.push_back(m[x][j++]);
        }
        while (i < cur.size())
            next.push_back(cur[i++]);
        while (j < m[x].size())
            next.push_back(m[x][j++]);
        int last = -1, tans = 0;
        for (auto vl : next) {
            // cerr << vl << " ";
            int elems = vl - last - 1;
            tans += elems * (elems + 1) / 2;
            last = vl;
        }
        int elems = n - last - 1;
        tans += elems * (elems + 1) / 2;
        // cerr << endl;
        cout << tans << " ";
        cur = next;
    }
    // cerr << endl;
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