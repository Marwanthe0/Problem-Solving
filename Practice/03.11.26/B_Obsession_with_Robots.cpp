#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())

vector<pair<int, int>> path = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
void marwan() {
    string s;
    cin >> s;
    int x = 0, y = 0;
    map<pair<int, int>, int> vis;
    vis[{x, y}]++;
    for (auto c : s) {
        int tx = x, ty = y;
        if (c == 'L')
            x--;
        else if (c == 'R')
            x++;
        else if (c == 'U')
            y++;
        else
            y--;
        for (auto [xx, yy] : path) {
            xx += x, yy += y;
            if (xx == tx && yy == ty)
                continue;
            if (vis.count({xx, yy})) {
                cout << "BUG" << endl;
                return;
            }
        }
        if (vis.count({x, y})) {
            cout << "BUG" << endl;
            return;
        }
        vis[{x, y}]++;
    }
    cout << "OK" << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}