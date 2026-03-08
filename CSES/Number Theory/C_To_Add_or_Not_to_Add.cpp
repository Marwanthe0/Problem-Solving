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
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), pr;
    for (auto &vl : v) {
        cin >> vl;
    }
    sort(all(v));
    for (int i = 0; i < n; i++) {
        pr.push_back(v[i] + (i ? pr.back() : 0ll));
    }
    int ans = 1, ansval = v[0];
    for (int i = 1; i < n; i++) {
        int l = 0, r = i - 1, elem = 1;
        //cerr << v[i] << endl;
        while (l <= r) {
            int m = l + (r - l) / 2ll;
            int dist = i - m;
            int remsum = pr[i - 1] - ((m > 0) ? pr[m - 1] : 0);
            //cerr << dist << " " << m << " " << remsum << endl;
            if (dist * v[i] - remsum <= k) {
                elem = (i - m + 1), r = m - 1;
            } else
                l = m + 1;
        }
        //cerr << v[i] << ":" << elem << endl;
        if (elem > ans)
            ans = elem, ansval = v[i];
    }
    cout << ans << " " << ansval << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}