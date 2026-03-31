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
    int n, m;
    cin >> n >> m;
    vector<string> v(m);
    set<char> first;
    vector<unordered_set<char>> t(n);
    for (auto &vl : v) {
        cin >> vl;
        for (int i = 0; i < n; i++) {
            t[i].insert(vl[i]);
            if (i == 0)
                first.insert(vl[i]);
        }
    }
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i)
                div.push_back(n / i);
        }
    }
    sort(all(div));
    // for (auto vl : div)
    //     cout << vl << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << t[i].size() << " ";
    // }
    // cout << endl;
    string ans;
    for (auto d : div) {
        int count = 0;
        string tans;
        // cerr << d << "::" << endl;
        for (int i = 1; i <= d; i++) {
            int mask = (1 << 28) - 1;
            for (int j = i - 1; j < n; j += d) {
                int task = 0;
                for (auto c : t[j]) {
                    task = (task | (1 << (c - 'a')));
                }
                mask = (mask & task);
            }
            // cerr << i << " " << mask << endl;
            if (mask) {
                tans.push_back('a' + (__lg(mask)));
                count++;
            }
        }
        // cerr << d << " d and count " << count << endl;
        if (count == d) {
            for (int i = 0; i < n / d; i++) {
                cout << tans;
            }
            cout << endl;
            return;
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