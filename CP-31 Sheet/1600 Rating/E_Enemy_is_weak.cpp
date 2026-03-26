#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
template <typename T>
using pbds = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    pbds<int> pb, tb;
    vector<int> second(n), third(n);
    for (int i = 0; i < n; i++) {
        second[i] = pb.order_of_key(v[i]);
        pb.insert(v[i]);
    }
    int ans = 0ll;
    for (int i = n - 1; i >= 0; i--) {
        third[i] = tb.order_of_key(-1 * v[i]);
        ans += (second[i] * 1ll * third[i]);
        tb.insert(-1 * v[i]);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}