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
void print(char c, int n) {
    for (int i = 1; i <= n; i++)
        cout << c;
}
void marwan() {
    int n, m, count = 0;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (auto &row : v) {
        for (auto &vl : row) {
            cin >> vl;
            count += vl;
        }
    }
    int ans = (count / 2) + (count % 2 != 0);
    cout << ans * (count / 2) << endl;

    count = 0;
    int down = 0, baki = ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            count += v[i][j];
        }
        if (count <= ans) {
            down++, baki = ans - count;
        } else
            break;
    }
    cerr << down << " " << baki << endl;
    print('D', down);
    count = 0;
    int rem = m;
    if (down != n) {
        for (int j = m - 1; j >= 0; j--) {
            if (baki <= 0) {
                cout << 'R';
                rem--;
            }
            baki -= v[down][j];
        }
        cout << "D";
    }
    print('R', rem);
    print('D', n - down - 1);
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