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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &vl : a)
        cin >> vl;
    for (auto &vl : b)
        cin >> vl;
    int l = n - 1;
    unordered_set<int> x, y;
    for (int i = 0; i <= l; i++) {
        if (i < n - k) {
            if (b[i] != -1) {
                if (a[i] != b[i]) {
                    no;
                    return;
                }
            }
            if (b[l] != -1) {
                if (a[l] != b[l]) {
                    no;
                    return;
                }
            }
            l--;
        } else {
            y.insert(a[i]);
            if (b[i] != -1) {
                if (x.count(b[i])) {
                    no;
                    return;
                }
                x.insert(b[i]);
            }
        }
    }
    for (auto vl : x) {
        if (!y.count(vl)) {
            no;
            return;
        }
    }
    yes;
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