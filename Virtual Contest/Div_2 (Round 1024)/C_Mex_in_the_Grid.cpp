#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> v(n, vector<int>(n, -1));
    int r = (n / 2) - 1;
    int c = (n / 2) - 1;
    v[r][c] = 0;
    v[r][c + 1] = 1;
    v[r + 1][c] = 2;
    v[r + 1][c + 1] = 3;
    int current = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == -1) {
                v[i][j] = current++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}