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
void marwan() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a, b;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            count++;
        } else if (count) {
            a.push_back(count);
            count = 0;
        }
    }
    if (count)
        a.push_back(count);
    count = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x) {
            count++;
        } else if (count) {
            b.push_back(count);
            count = 0;
        }
    }
    if (count)
        b.push_back(count);
    // for (auto vl : a)
    //     cerr << vl << " ";
    // cerr << endl;
    // for (auto vl : b)
    //     cerr << vl << " ";
    // cerr << endl;
    sort(all(a));
    sort(all(b));
    // vector<int> pra, prb;
    // for (auto vl : a) {
    //     pra.push_back(pra.empty() ? vl : pra.back() + vl);
    // }
    // for (auto vl : b)
    //     prb.push_back(prb.empty() ? vl : prb.back() + vl);
    vector<int> dv;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            dv.push_back(i);
            if (k / i != i)
                dv.push_back(k / i);
        }
    }
    // for (auto vl : dv)
    //     cerr << vl << " ";
    // cerr << endl;
    sort(all(dv));
    int ans = 0;
    for (auto vl : dv) {
        int dl = k / vl;
        for (auto it = lower_bound(all(a), vl); it != a.end(); it++) {
            for (auto tt = lower_bound(all(b), dl); tt != b.end(); tt++) {
                // cerr << *it << " " << *tt << endl;
                ans += (*it - vl + 1) * (*tt - dl + 1);
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