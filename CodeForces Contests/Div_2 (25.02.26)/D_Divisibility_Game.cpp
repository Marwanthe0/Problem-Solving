#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Alice" << endl
#define no cout << "Bob" << endl
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n, m;
    cin >> n >> m;
    set<int> s;
    vector<int> v(m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    unordered_map<int, int> mp;
    int mx = INT_MIN;
    for (int i = 0; i < m; i++) {
        cin >> v[i];
        mp[v[i]]++;
        mx = max(mx, v[i]);
    }
    int alice = 0, bob = 0, common = 0;
    vector<int> div(mx + 1, 0);
    for (auto vl : s) {
        if (vl == 1) {
            for (auto val : mp)
                div[val.first]++;
            continue;
        }
        for (int i = vl; i <= mx; i += vl) {
            div[i]++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (div[v[i]])
            alice++;
        if (s.size() > div[v[i]])
            bob++;
        if (div[v[i]] && s.size() > div[v[i]])
            common++;
    }
    // cout << alice << " " << bob << " " << common << endl;
    if (alice > bob || (alice == bob && (common % 2)))
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