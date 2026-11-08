#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
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
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
void marwan(int cs) {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    pbds<int> pb;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pb.insert(i);
    }
    while (q--) {
        char op;
        cin >> op;
        if (op == 'c') {
            int idx;
            cin >> idx;
            idx--;
            if (idx < pb.size()) {
                auto it = pb.find_by_order(idx);
                cout << v[*it] << endl;
                pb.erase(it);
            } else {
                cout << "none" << endl;
            }
        } else {
            int val;
            cin >> val;
            pb.insert(v.size());
            v.push_back(val);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}