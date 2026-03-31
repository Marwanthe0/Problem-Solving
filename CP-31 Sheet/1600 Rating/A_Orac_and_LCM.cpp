#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 200000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
vector<int> spf(N + 1, 0);
void sieve() {
    spf[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            if (!spf[j])
                spf[j] = i;
        }
    }
}
int pw(int a, int b) {
    return pow(a, b);
}
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    unordered_map<int, vector<int>> m;
    for (auto vl : v) {
        int x = vl;
        unordered_map<int, int> temp;
        while (spf[x] != x) {
            temp[spf[x]]++;
            x /= spf[x];
        }
        if (x != 1) {
            // cerr << x << endl;
            temp[x]++;
        }
        for (auto &[x, y] : temp) {
            m[x].push_back(y);
        }
        // cerr << endl;
    }
    int ans = 1ll;
    for (auto &[x, y] : m) {
        if (y.size() < n - 1)
            continue;
        if (y.size() == n - 1)
            y.push_back(0);
        sort(all(y));
        // cerr << x << " er jonnyo " << ((y.size() == n) ? y[1] : y[0]) << " ";
        ans = (ans * 1ll * pw(x, (y.size() == n) ? y[1] : y[0]));
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    sieve();
    marwan();
    return 0;
}