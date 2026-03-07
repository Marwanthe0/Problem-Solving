#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000000
#define endl "\n"
#define all(v) v.begin(), v.end()
#define forn for (int i = 0; i < n; i++)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
void marwan() {
    int x, y, m;
    cin >> x >> y >> m;
    for (int i = 0; i <= m; i += x) {
        for (int j = 0; j <= m; j += y) {
            if (i + j == m) {
                yes;
                return;
            }
        }
    }
    no;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}