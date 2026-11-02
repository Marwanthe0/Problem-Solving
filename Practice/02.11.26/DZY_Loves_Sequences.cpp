#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n), pf(n, 1), sf(n, 1);
    for (auto &vl : v)
        cin >> vl;
    int ans = 1, count = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1])
            count++;
        else
            count = 1;
        pf[i] = count;
        ans = max(ans, count);
    }
    count = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] < v[i + 1])
            count++;
        else
            count = 1;
        sf[i] = count;
    }
    // for (int i = 0; i < n; i++)
    //     cerr << pf[i] << " ";
    // cerr << endl;
    // for (int i = 0; i < n; i++)
    //     cerr << sf[i] << " ";
    // cerr << endl;
    for (int i = 1; i + 1 < n; i++) {
        if (v[i + 1] - v[i - 1] >= 2)
            ans = max(ans, pf[i - 1] + sf[i + 1] + 1);
        else
            ans = max(ans, max(pf[i - 1] + 1, sf[i + 1] + 1));
    }
    if (n >= 2)
        ans = max(ans, max(pf[n - 2] + 1, sf[1] + 1));
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}