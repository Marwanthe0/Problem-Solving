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
    int n, k;
    cin >> k >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int l = 0, r = k, ans = 0;
    auto ok = [&](int mid) {
        int sum = 0ll;
        for (auto vl : v) {
            sum += min(vl, mid);
            if (sum > k)
                return false;
        }
        return sum <= k;
    };
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid, l = mid + 1;
        } else
            r = mid - 1;
    }
    // cout << ans << endl;
    vector<int> uttor(n);
    int sum = 0ll, tk = k;
    for (int i = 0; i < n; i++) {
        uttor[i] = min(v[i], ans);
        tk -= uttor[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (tk > 0 && uttor[i] < v[i]) {
            uttor[i]++;
            tk--;
        }
    }
    for (auto vl : uttor)
        cout << vl << " ";
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