#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 5e5
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
vector<int> spf(N + 1, -1);
void pre() {
    for (int i = 2; i <= N; i++) {
        if (spf[i] != -1)
            continue;
        for (int j = i; j <= N; j += i) {
            if (spf[j] == -1)
                spf[j] = i;
        }
    }
}
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        int x = vl;
        while (x != 1) {
            m[spf[x]]++;
            x = x / spf[x];
        }
    }
    int ans = 1ll;
    for (auto [x, y] : m) {
        ans = (ans * 1ll * (y + 1)) % M;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin >> t;
    while (t--) {
        marwan();
    }
    return 0;
}