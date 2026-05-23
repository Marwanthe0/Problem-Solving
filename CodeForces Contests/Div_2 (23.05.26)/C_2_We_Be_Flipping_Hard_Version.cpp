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
    vector<int> v(n), sf(n, 0), pf(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pf[i] += abs(v[i]);
        if (i)
            pf[i] += pf[i - 1];
    }
    int sum = accumulate(all(v), 0ll);
    for (int i = n - 1; i >= 0; i--) {
        sf[i] = v[i];
        if (i != n - 1)
            sf[i] += sf[i + 1];
    }
    int pos = -1, val = sum;
    for (int i = 0; i < n; i++) {
        if (v[i] > 0) {
            int tval = -v[i] + (i ? pf[i - 1] : 0) + ((i != n - 1) ? sf[i + 1] : 0);
            if (tval > val)
                val = tval, pos = i;
        }
    }
    if (pos == -1) {
        cout << 0 << endl;
        cout << endl;
        return;
    }
    bool flag = true;
    vector<int> ans;
    for (int i = pos - 1; i >= 0; i--) {
        if (flag) {
            if (v[i] > 0) {
                ans.push_back(i + 1);
                flag = false;
            }
        } else {
            if (v[i] < 0) {
                ans.push_back(i + 1);
                flag = true;
            }
        }
    }
    ans.push_back(pos + 1);
    cout << ans.size() << endl;
    for (auto &vl : ans)
        cout << vl << " ";
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