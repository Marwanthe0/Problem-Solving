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
vector<int> v, upore, niche;
int dfs(int u, int sum) {

    upore[u] = sum;
    int left = 2 * u, right = 2 * u + 1;
    if (left < n) {
        niche[u] = v[left] + dfs(left, sum + v[left]);
    }
    if (right < n)
        niche[u] = max(niche[u], v[right] + dfs(right, sum + v[right]));
    return niche[u];
}
void dfs2(int u, int val) {
    upore[u] += val;
    int left = 2 * u, right = 2 * u + 1;
    if (left < n)
        dfs2(left, val);
    if (right < n)
        dfs2(right, val);
}
void marwan() {
    cin >> n;
    n = (1 << (n + 1));
    v.assign(n, 0);
    upore.assign(n, 0);
    niche.assign(n, 0);
    for (int i = 2; i < n; i++) {
        cin >> v[i];
    }
    dfs(1, v[1]);
    int mx = niche[1];
    // for (int i = 1; i < n; i++) {
    //     cout << i << " " << v[i] << " " << upore[i] << " " << niche[i] << endl;
    // }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        // cerr << i << " " << v[i] << " " << upore[i] << " " << niche[i] << endl;
        int lagbe = mx - (upore[i] + niche[i]);
        // cerr << i << " " << lagbe << endl;
        ans += lagbe;
        if (lagbe)
            dfs2(i, lagbe);
    }
    cout << ans << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    marwan();
    return 0;
}