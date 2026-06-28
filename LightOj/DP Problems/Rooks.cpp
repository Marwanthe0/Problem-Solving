#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n, k;
vector<vector<int>> vis;
int f(int i, int j, int king) {
    if (!vis[i][j])
        vis[i][j] = 1;
}
void marwan(int tc) {
    cin >> n >> k;
    vis.assign(n + 1, vector<int>(n + 1, 0));
    int ans = f(1, 1, k);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        marwan(i);
    return 0;
}