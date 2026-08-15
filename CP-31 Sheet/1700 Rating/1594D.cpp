#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, k;
map<int, map<int, int>> m;
vector<int> vis;
int f(int i, bool shothik) {
    if (!m.count(i))
        return 1;
    cout << i << endl;
    for (auto mchild : m[i]) {
        cout << mchild.first << " " << mchild.second << endl;
        cout << endl;
    }
    cout << endl;
    return 0;
}
void marwan() {
    cin >> n >> k;
    bool flag = true;
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b;
        string s;
        cin >> s;
        if (s == "imposter")
            c = 0;
        else
            c = 1;
        if (!flag)
            continue;
        if (m.count(a) && m[a].count(b)) {
            if (c != m[a][b]) {
                flag = false;
                continue;
            }
        } else {
            m[a][b] = c;
        }
    }
    if (!flag) {
        minus;
        return;
    }
    // return;
    vis.assign(n + 1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans += max(f(i, 0), f(i, 1));
        }
    }
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