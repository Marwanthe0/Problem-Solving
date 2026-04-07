#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int count = 0, count2 = 0;
        int x = 2 * n - v[i];
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if ((i > j && v[j] > v[i]) || (i < j && v[j] < v[i]))
                count++;
            if ((i > j && v[j] > x) || (i < j && v[j] < x))
                count2++;
        }
        // cerr << i << "::" << count << " " << count2 << endl;
        if (count2 < count)
            v[i] = x;
    }
    for (int i = 0; i < n; i++) {
        // cerr << v[i] << " ";
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j])
                ans++;
        }
    }
    // cerr << endl;
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