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
    int n, p;
    cin >> n >> p;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> t;
    for (int i = 1; i < n - 1; i++)
        t.push_back(v[i]);
    int val = 0;
    int x = *min_element(all(t));
    if (p == 1 || p == n) {
        val = v[p - 1];
        x = min(x, val);
    }
    sort(all(t));
    int tn = n;
    n = t.size();
    for (auto vl : t)
        x = min(x, val ^ vl);
    for (int i = 1; i < n; i++) {
        x = min(x, val ^ t[i] ^ t[i - 1]);
    }
    int K = 100;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < min(n, i + K); j++) {
            for (int k = j + 1; k < min(n, i + K); k++) {
                x = min(x, val ^ t[i] ^ t[j] ^ t[k]);
            }
        }
    }
    cout << x << endl;
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