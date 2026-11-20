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
int cnt = 0;
int binexp(int a, int b) {
    int ans = 1ll;
    while (b) {
        if (b & 1)
            ans = (ans * 1ll * a) % M;
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans;
}
void marwan(int cs) {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    vector<int> t;
    make_unique(v);
    reverse(all(v));
    int ans = m[v[0]] == 1 ? v[0] : 1;
    if (m[v[0]] != 1) {
        cout << 1 << endl;
        return;
    }
    int cnt = 2;
    for (int i = 1; i < v.size(); i++) {
        if (m[v[i]] == 1) {
            ans = (ans + (binexp(v[i] - 1, cnt) % M)) % M;
            cnt++;
        } else
            break;
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        marwan(i);
    }
    return 0;
}