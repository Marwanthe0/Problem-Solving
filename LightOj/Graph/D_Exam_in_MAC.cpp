#include <bits/stdc++.h>
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
void marwan(int cs) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    set<int> st;
    for (auto &vl : v) {
        cin >> vl;
        st.insert(vl);
    }
    for (int i = 0; i <= k; i++) {
        for (int j = i; j <= k; j++) {
            if (st.count(j - i) && st.count(i + j))
                cout << i << " " << j << " :: " << st.count(j - i) << " " << st.count(i + j) << endl;
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