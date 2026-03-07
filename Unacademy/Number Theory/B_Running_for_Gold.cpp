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
    vector<vector<int>> v(n, vector<int>(5)), mn(5);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> v[i][j];
            mn[j].push_back(v[i][j]);
        }
    }
    for (int i = 0; i < 5; i++) {
        sort(all(mn[i]));
        for (auto vl : mn[i])
            cerr << vl << " ";
        cerr << endl;
    }
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (n > 1 && mn[j][0] == mn[j][1])
                continue;
            if (v[i][j] == mn[j][0])
                count++;
            if (count >= 3) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
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