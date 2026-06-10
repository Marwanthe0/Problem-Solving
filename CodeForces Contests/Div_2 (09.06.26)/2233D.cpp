#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1e6
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
void marwan() {
    int n;
    cin >> n;
    vector<int> v, lcheck(n, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        lcheck[i] = x;
        if (v.empty() || v.back() != x)
            v.push_back(x);
    }
    n = v.size();
    set<int> st(all(v));
    if (st.size() == n) {
        yes;
        return;
    }
    map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++) {
        if (m.count(v[i]))
            m[v[i]].second = i;
        else
            m[v[i]] = {i, i};
    }
    vector<int> cand;
    for (auto [x, y] : m) {
        if (y.first != y.second)
            cand.push_back(x);
    }
    if (cand.size() > 2) {
        no;
        return;
    } else if (cand.size() == 1) {
        
    } else {
        if (m[cand[0]].first < m[cand[1]].first)
            reverse(all(cand));
        swap(v[m[cand[0]].first], v[m[cand[1]].second]);
    }
    vector<int> t;
    for (int i = 0; i < n; i++) {
        if (t.empty() || t.back() != v[i])
            t.push_back(v[i]);
    }
    if (t.size() == st.size())
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