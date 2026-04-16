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
#define minus cout << "-1" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())

int ok(vector<int> &v, int x, int y, int z) {
    if (x < y)
        swap(x, y);
    if (x <= v[0] && y <= v[1])
        return 0;
    else if (x <= v[0])
        return 1;
    else if (y <= v[0])
        return 2;
    else
        return 3;
}
void marwan() {
    vector<int> v(3), t(3);
    for (int i = 0; i < 3; i++)
        cin >> v[i];
    for (int j = 0; j < 3; j++)
        cin >> t[j];
    sort(all(v), greater<int>());
    int c = v.back(), x = t[0], y = t[1], z = t[2];
    int count = 0;
    while (1) {
        int k = ok(v, x, y, z);
        if (k == 0) {
            cout << count << endl;
            return;
        } else if (k == 1) {
            y /= 2, z *= 2;
            count++;
        } else if (k == 2) {
            x /= 2, z *= 2, count++;
        } else {
            if (x > y) {
                x /= 2;
            } else
                y /= 2;
            z *= 2;
            count++;
        }
        // cerr << x << " " << y << " " << z << endl;
    }
    // cerr << endl;
    minus;
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