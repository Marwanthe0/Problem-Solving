#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n), sf(n, 0), a;
    for (auto &vl : v)
        cin >> vl;
    for (int i = n - 1; i >= 0; i--) {
        auto it = upper_bound(all(a), -v[i]);
        sf[i] = it - a.begin() + 1;
        if (it == a.end()) {
            a.push_back(-v[i]);
        } else
            *it = v[i];
    }
    for (int i = 0; i < n; i++)
        cerr << sf[i] << " ";
    cerr << endl;
    a.clear();
    int ans = 1;
    set<int> st;
    vector<int> idx;
    for (int i = 0; i < n; i++) {
        auto it = upper_bound(all(a), v[i]);
        int len = it - a.begin() + 1;
        cerr << len << " ";
        for (int j = 0; j < n; j++) {
            if (!st.count(j))
                ans = max(ans, sf[j] + len);
        }
        if (it == a.end()) {
            a.push_back(v[i]);
            st.insert(i);
            idx.push_back(i);
        } else {
            st.erase(idx[it - a.begin()]);
            *it = v[i];
            idx[it - a.begin()] = i;
            st.insert(i);
        }
    }
    cerr << endl;
    cerr << endl;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}