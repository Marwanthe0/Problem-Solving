#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> pf(n, 0), tf(n, 0), df(n, 0);
    for (int i = 0; i < n; i++) {
        pf[i] = s[i] == t[i];
        if (s[i] != t[i])
            if (s[i] == '0')
                tf[i]++;
            else
                df[i]++;
        if (i)
            pf[i] += pf[i - 1], tf[i] += tf[i - 1], df[i] += df[i - 1];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        r--, l--;
        int len = r - l + 1;
        int ase = pf[r] - (l ? pf[l - 1] : 0);
        int nai = len - ase;
        int tff = tf[r] - (l ? tf[l - 1] : 0), dff = df[r] - (l ? df[l - 1] : 0);
        if (ase >= nai) {
            yes;
        } else {
            int lagbe = nai - ase;
            int aro = 2 * min(tff, dff);
            lagbe -= aro;
            if (lagbe > 0) {
                no;
            } else
                yes;
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