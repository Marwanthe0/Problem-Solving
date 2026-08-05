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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &vl : v)
        cin >> vl;
    vector<int> t;
    int ans = 0, sum = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        // t.push_back(0);
        m[0]++;
        // for (auto &vl : t)
        //     if (vl == v[i] - 1) {
        //         vl++;
        //         sum++;
        //     }
        int count = m[v[i] - 1];
        m[v[i] - 1] = 0;
        m[v[i]] += count;
        sum += count;
        // cout << sum << " ";
        ans += sum;
    }
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