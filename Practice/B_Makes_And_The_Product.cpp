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
void marwan() {
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> m;
    for (auto &vl : v) {
        cin >> vl;
        m[vl]++;
    }
    sort(all(v));
    int x = v[0], y = v[1], z = v[2];
    if (x == y && y == z) {
        int cnt = m[x];
        cout << (cnt * (cnt - 1) * (cnt - 2)) / 6ll;
        return;
    } else if (x == y) {
        cout << m[z] << endl;
        return;
    } else if (y == z) {
        int cnt = m[z];
        cout << (cnt * (cnt - 1)) / 2ll << endl;
        return;
    }
    cout << m[z] << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}