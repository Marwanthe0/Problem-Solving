#include <bits/stdc++.h>
using namespace std;
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
void marwan() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    vector<int> temp = v[0];
    sort(all(v), [&](vector<int> a, vector<int> b) { if(a[1] == b[1])
            return a[2] < b[2];
        return a[1] < b[1]; });
    vector<vector<int>> t(all(v));
    sort(all(t), [&](vector<int> a, vector<int> b) { if(a[2] == b[2])
            return a[1] < b[1];
        return a[2] < b[2]; });
    long double ans = 0ll, ans2 = 0ll;
    v.push_back(temp);
    t.push_back(temp);
    auto f = [&](int a, int b) {
        return (long double)sqrt(((a * a) + b * b));
    };
    for (int i = 1; i < n + 1; i++) {
        cerr << v[i - 1][1] << " " << v[i - 1][2] << endl;
        // cerr << v[i][1] << " " << v[i][2] << endl;
        int xi = v[i][1], xj = v[i - 1][1], yi = v[i][2], yj = v[i - 1][2];
        int xti = t[i][1], xtj = t[i - 1][1], yti = t[i][2], ytj = t[i - 1][2];
        ans += f(abs(xi - xj), abs(yi - yj));
        ans2 += f(abs(xti - xtj), abs(yti - ytj));
        // cerr << ans << endl;
    }
    // cerr << endl;
    cout << setprecision(6) << min(ans, ans2) << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}