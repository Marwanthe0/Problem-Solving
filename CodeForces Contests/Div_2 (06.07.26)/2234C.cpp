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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;

    auto pre = [&](int x) {
        x--;
        if (x < 0)
            x = n - 1;
        return x;
    };
    auto nxt = [&](int x) { x++; x %= n; return x; };
    for (int i = 0; i < n; i++) {
        vector<int> pr(n, -1), sf(n, -1);
        pr[i] = sf[i] = 0;
        for (int j = i + 1, k = 1; k < n; j++, k++) {
            j %= n;
            int age = pre(j), pore = nxt(j);
            pr[j] = max(pr[age], v[age]);
        }
        for (int j = i - 1, k = 1; k < n; k++) {
            if (j < 0)
                j = n - 1;
            int age = pre(j), pore = nxt(j);
            sf[j] = max(sf[pore], v[j]);
            j = pre(j);
        }
        int uttor = 0ll;
        for (int i = 0; i < n; i++)
            uttor += min(pr[i], sf[i]);
        cout << uttor << " ";
        // for (auto vl : pr)
        //     cerr << vl << " ";
        // cerr << endl;
        // for (auto vl : sf)
        //     cerr << vl << " ";
        // cerr << endl;
    }
    cerr << endl;
    cout << endl;
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