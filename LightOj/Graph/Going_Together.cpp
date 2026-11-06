#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define M 1000000007
#define N 1000005
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<pair<int, int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dist[10][10][10][10][10][10];
struct Node {
    int x[3], y[3];
};
void marwan(int cs) {
    cin >> n;
    vector<string> g(n);

    Node src;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        for (int j = 0; j < n; j++) {
            if (g[i][j] >= 'A' && g[i][j] <= 'C') {
                src.x[g[i][j] - 'A'] = i;
                src.y[g[i][j] - 'A'] = j;
            }
        }
    }

    auto valid = [&](int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < n && g[i][j] != '#');
    };
    memset(dist, -1, sizeof(dist));
    queue<Node> q;

    q.push(src);
    dist[src.x[0]][src.y[0]][src.x[1]][src.y[1]][src.x[2]][src.y[2]] = 0;

    int ans = -1;
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        int d = dist[cur.x[0]][cur.y[0]][cur.x[1]][cur.y[1]][cur.x[2]][cur.y[2]];

        if (g[cur.x[0]][cur.y[0]] == 'X' && g[cur.x[1]][cur.y[1]] == 'X' && g[cur.x[2]][cur.y[2]] == 'X') {
            ans = d;
            break;
        }

        for (auto [x, y] : path) {
            Node next = cur;

            for (int i = 0; i < 3; i++) {
                int nx = x + cur.x[i], ny = y + cur.y[i];
                if (valid(nx, ny)) {
                    next.x[i] = nx;
                    next.y[i] = ny;
                }
            }

            while (1) {
                bool flag = true;
                for (int i = 0; i < 3; i++) {         // X
                    for (int j = i + 1; j < 3; j++) { // Y
                        if (next.x[i] == next.x[j] && next.y[i] == next.y[j]) {
                            next.x[i] = cur.x[i];
                            next.y[i] = cur.y[i];

                            next.x[j] = cur.x[j];
                            next.y[j] = cur.y[j];
                            flag = false;
                        }
                    }
                }
                if (flag)
                    break;
            }

            if (dist[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]] == -1) {
                dist[next.x[0]][next.y[0]][next.x[1]][next.y[1]][next.x[2]][next.y[2]] = d + 1;
                q.push(next);
            }
        }
    }
    if (ans == -1)
        cout << "trapped" << endl;
    else
        cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        marwan(i);
    }
    return 0;
}