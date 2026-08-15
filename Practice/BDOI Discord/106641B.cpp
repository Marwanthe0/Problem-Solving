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
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
void marwan() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> v;
    pbds<int> pb;
    vector<int> pf(n + 1, 0);
    int count = 0;
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            count++;
        } else if (op == 2) {
            int y;
            cin >> y;
            // cerr << i << "::aage" << endl;
            // for (auto vl : pb)
            //     cerr << vl << " ";
            // cerr << pf[y];
            // cerr << endl;
            if (count > pf[y]) {
                if (pf[y])
                    pb.erase(pb.upper_bound(pf[y]));
                pf[y] = count;
                pb.insert(pf[y]);
            }
            // cerr << i << "::pore" << endl;
            // for (auto vl : pb)
            //     cerr << vl << " ";
            // cerr << endl;
        } else {
            int y;
            cin >> y;
            if (y > count) {
                cout << 0 << endl;
                continue;
            }
            cout << pb.size() - pb.order_of_key(y) << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}