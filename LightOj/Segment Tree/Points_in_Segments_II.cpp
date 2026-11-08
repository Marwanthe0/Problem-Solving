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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
        v.push_back({x, y});
    }
    sort(all(v));
    sort(all(a));
    sort(all(b));
    // for (auto [x, y] : v)
    //     cout << x << " " << y << endl;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        int start_hoyeche = upper_bound(all(a), x) - a.begin();
        int shesh_hoye_geche = lower_bound(all(b), x) - b.begin();
        int start_hoyeche_kintu_shesh_hoyni = start_hoyeche - shesh_hoye_geche;
        // cerr << start_hoyeche << " " << shesh_hoye_geche << endl;
        cout << start_hoyeche_kintu_shesh_hoyni << endl;
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