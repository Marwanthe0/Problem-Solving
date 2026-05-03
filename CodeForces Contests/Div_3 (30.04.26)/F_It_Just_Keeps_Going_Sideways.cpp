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

void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> frq;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += (i + 1) * v[i];
        frq[v[i]]++;
    }
    vector<int> a(n + 2, 0ll);
    for (int i = n; i >= 1; i--) {
        a[i] = a[i + 1] + frq[i];
    }
    int sum1 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i])
            sum1 += (a[i] * (2 * n - a[i] + 1)) / 2ll;
    }

    int dst = sum1 - sum;
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        int tans = (i + 1) - (n - a[v[i]] + 1);
        ans = max(ans, tans);
    }
    ans += dst;
    cout << ans << endl;
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