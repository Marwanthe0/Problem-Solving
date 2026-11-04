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
int n, q;
vector<vector<int>> v;
class SparseTable2D {
    int n, m, KX, KY;
    vector<int> lgN, lgM;
    using Table = vector<vector<vector<vector<int>>>>;
    Table mx;

  public:
    SparseTable2D(vector<vector<int>> &a) {
        n = a.size();
        m = a[0].size();
        // Calculate logarithms
        lgN.assign(n + 1, 0);
        lgM.assign(m + 1, 0);
        for (int i = 2; i <= n; i++)
            lgN[i] = lgN[i / 2] + 1;
        for (int j = 2; j <= m; j++)
            lgM[j] = lgM[j / 2] + 1;
        KX = lgN[n] + 1;
        KY = lgM[m] + 1;
        // Aintocate tables

        mx.assign(KX, vector<vector<vector<int>>>(KY, vector<vector<int>>(n, vector<int>(m))));

        // Level 0, 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mx[0][0][i][j] = a[i][j];
            }
        }
        // Step 1: Horizontal merging
        for (int ky = 1; ky < KY; ky++) {
            int len = (1 << ky), half = (1 << (ky - 1));

            for (int i = 0; i < n; i++) {
                for (int j = 0; j + len <= m; j++) {

                    mx[0][ky][i][j] = max(mx[0][ky - 1][i][j], mx[0][ky - 1][i][j + half]);
                }
            }
        }

        // Step 2: Vertical merging
        for (int kx = 1; kx < KX; kx++) {

            int len = (1 << kx), half = (1 << (kx - 1));
            for (int ky = 0; ky < KY; ky++) {
                int width = (1 << ky);
                for (int i = 0; i + len <= n; i++) {
                    for (int j = 0; j + width <= m; j++) {

                        mx[kx][ky][i][j] = max(mx[kx - 1][ky][i][j], mx[kx - 1][ky][i + half][j]);
                    }
                }
            }
        }
    }

    // Range Maximum Query
    int queryMax(int x1, int y1, int x2, int y2) {
        int kx = lgN[x2 - x1 + 1];
        int ky = lgM[y2 - y1 + 1];
        int h = (1 << kx);
        int w = (1 << ky);
        return max({mx[kx][ky][x1][y1], mx[kx][ky][x1][y2 - w + 1], mx[kx][ky][x2 - h + 1][y1], mx[kx][ky][x2 - h + 1][y2 - w + 1]});
    }
};
void marwan(int cs) {
    cin >> n >> q;
    v.assign(n, vector<int>(n, 0));
    for (auto &row : v) {
        for (auto &vl : row)
            cin >> vl;
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++)
    //         cout << v[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    SparseTable2D sp2d(v);
    while (q--) {
        int i, j, len;
        cin >> i >> j >> len;
        i--, j--;
        cout << sp2d.queryMax(i, j, i + len - 1, j + len - 1) << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":" << endl;
        marwan(i);
    }
    return 0;
}