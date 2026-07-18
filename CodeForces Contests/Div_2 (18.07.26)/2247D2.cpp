#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
void marwan() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    pbds<int> pb;
    for (auto &vl : v) {
        cin >> vl;
        pb.insert(vl);
    }
    int ans = 0ll;
    for (int i = 0; i < n; i++) {
        int cpr = pb.order_of_key(v[i]);
        ans = max(ans, 1ll << __lg(cpr ^ i));
    }
    cout << ans << endl;
    while (k--) {
        int idx, val;
        cin >> idx >> val;
        pb.erase(pb.find(v[idx]));
        pb.insert(val);
        cerr<<idx<<" "<<
        ans = max(ans, 1ll << __lg(idx ^ pb.order_of_key(val)));
        cout << ans << endl;
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