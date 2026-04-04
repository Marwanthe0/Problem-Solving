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
void marwan() {
    int n;
    cin >> n;
    int x = n + 1, y = n + 2;
    vector<vector<int>> v(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++, x += 2, y += 2) {
        v[i][0] = (i + 1);
        v[i][1] = x;
        v[i][2] = y;
    }
    for (auto val : v) {
        for (auto vl : val)
            cout << vl << " ";
    }
    cout << endl;
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