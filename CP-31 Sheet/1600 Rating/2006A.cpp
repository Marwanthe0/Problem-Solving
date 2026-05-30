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
void dfs(int nd, int par, vector<vector<int>> &g, unordered_set<int> &leaves) {
    bool flag = true;
    for (auto child : g[nd]) {
        if (child == par)
            continue;
        flag = false;
        dfs(child, nd, g, leaves);
    }
    if (flag)
        leaves.insert(nd);
}
void marwan() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string s;
    cin >> s;
    bool alice = true, talice;
    int root = -1;
    if (s[0] != '?') {
        root = s[0] - '0';
    } else
        alice = false;
    int extra = 0;
    unordered_set<int> leaves;
    dfs(1, 0, g, leaves);
    for (int i = 1; i < n; i++) {
        if (leaves.count(i + 1))
            continue;
        else if (s[i] == '?')
            extra++;
    }
    if (extra & 1) {
        talice = !alice;
    } else
        talice = alice;
    int ans = 0ll, tans = 0ll;
    // cerr << alice << " " << talice << endl;
    if (root == -1) {
        int one = 0, zero = 0;
        for (auto l : leaves) {
            if (s[l - 1] == '?')
                continue;
            if ((s[l - 1]) == '1')
                one++;
            else
                zero++;
        }
        if (one > zero)
            root = 0;
        else
            root = 1;
        if (one != zero) {
            if (talice != alice)
                talice = alice;
        }
    }
    if (root == 0) {
        for (auto l : leaves) {
            int i = l - 1;
            if (s[i] == '?') {
                if (alice) {
                    ans++;
                }
                if (talice) {
                    tans++;
                }
                alice = !alice;
                talice = !talice;
            } else if (s[i] == '1')
                ans++, tans++;
        }
    } else {
        for (auto l : leaves) {
            int i = l - 1;
            if (s[i] == '?') {
                if (alice) {
                    ans++;
                }
                if (talice)
                    tans++;
                alice = !alice;
                talice = !talice;
            } else if (s[i] == '0')
                ans++, tans++;
        }
    }
    // cerr << ans << " " << tans << endl;
    cout << max(ans, tans) << endl;
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