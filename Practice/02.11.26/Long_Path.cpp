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
int n;
vector<int> v, vis;
int dfs(int cur) {
    if (cur == n + 1)
        return 0;
    vis[cur]++;
    if (vis[cur] & 1)
        return 1 + dfs(v[cur]);
    else
        return 1 + dfs(cur + 1);
}
void marwan() {
    cin >> n;
    v.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cout << dfs(1) << endl;
    for (int i = 1; i <= n; i++)
        cout << vis[i] << " ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}