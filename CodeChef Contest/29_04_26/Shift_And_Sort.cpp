#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int last = -5;
    for (int i = 0; i + 1 < n; i++) {
        if (v[i] > v[i + 1] && last + 1 == i) {
            no;
            return;
        }
        if (v[i] > v[i + 1]) {
            int x = v[i], y = v[i + 1];
            v[i] = (x + y) / 2;
            v[i + 1] = (x + y) / 2 + ((x + y) % 2);
            last = i;
        }
    }
    if (is_sorted(all(v)))
        yes;
    else
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