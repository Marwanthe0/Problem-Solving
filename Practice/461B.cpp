#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 1e6
#define INF 1e17
#define endl "\n"
#define all(v) v.begin(), v.end()
#define minus cout << "-1" << endl
#define zero cout << "0" << endl
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define make_unique(x) \
    sort(all((x)));    \
    (x).erase(unique(all((x))), (x).end())
int n;
vector<vector<int>> g;
vector<int> v;
int f(int nd, int p) {
    int ans = 0;
    for (auto child : g[nd]) {
        if (child != p) {
            f(child, nd);
        }
    }
}
void marwan() {
    cin >> n;
    g.assign(n, vector<int>());
    v.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
    }
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = f(0, -1);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    marwan();
    return 0;
}