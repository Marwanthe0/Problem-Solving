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
    string s;
    cin >> s;
    multiset<char> ms;
    for (auto c : s)
        ms.insert(c);
    string t, ts;
    unordered_set<int> ind;
    for (int i = 0; i < n; i++) {
        if (s[i] == *(--ms.end())) {
            t.push_back(s[i]);
            ind.insert(i);
        }
        ms.erase(ms.find(s[i]));
    }
    // cout << t << endl;
    string tt = t;
    sort(all(tt));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (ind.count(i)) {
            ts.push_back(tt[j++]);
        } else
            ts.push_back(s[i]);
    }
    if (is_sorted(all(ts))) {
        int count = 0, idx = 1;
        while (idx < t.size() && t[idx] == t[0])
            count++, idx++;
        cout << (t.size() - 1) - count << endl;
    } else
        minus;
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