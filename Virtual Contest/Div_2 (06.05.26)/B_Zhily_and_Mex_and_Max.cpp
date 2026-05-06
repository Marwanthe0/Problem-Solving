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
    vector<int> v(n), ans;
    set<int> s;
    for (auto &vl : v) {
        cin >> vl;
        s.insert(vl);
    }
    ans.push_back(*(--s.end()));
    s.erase(--s.end());
    for (auto vl : s)
        ans.push_back(vl);
    while (ans.size() < n)
        ans.push_back(-1);
    // for (auto vl : ans)
    //     cout << vl << " ";
    // cout << endl;
    int uttor = 0, mx = 0, mex = 0;
    unordered_set<int> vd;
    for (int i = 0; i < n; i++) {
        mx = max(mx, ans[i]);
        vd.insert(ans[i]);
        while (vd.count(mex))
            mex++;
        uttor += (mx + mex);
    }
    cout << uttor << endl;
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